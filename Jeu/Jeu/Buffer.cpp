#include "Buffer.h"


#pragma warning (disable : 4996)
#pragma comment( lib, "winmm" )
#include <stdio.h>
#include <sstream>
#include <Windows.h>
#include <string>
#include <fstream>
using namespace std;
Buffer::Buffer()
{
	hOutput = (HANDLE)GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,dwBufferCoord, &rcRegion);
	
	_Assets.LoadPlayerFromFile("test1.txt");
	_Assets.LoadPlayerFromFile("ship.txt");
	_Assets.LoadPlayerFromFile("ship2.txt");
}
Buffer::~Buffer()
{
}


void Buffer::Update(int x, int y, char c) {
	buffer[x][y].Char.AsciiChar = c;
}

void Buffer::Update(int x, int y, char c, char color)
{
	buffer[x][y].Char.AsciiChar = c;
	buffer[x][y].Attributes = color;
}

void Buffer::CheckAndUpdate(int x, int y, char c, char color)
{
	if (x >= 0 && y >= 0 && y < SCREEN_WIDTH && x < SCREEN_HEIGHT) {
		buffer[x][y].Char.AsciiChar = c;
		buffer[x][y].Attributes = color;
	}
}

void Buffer::UpdateFromAsset(int x, int y, string AssetName) {

	UpdateWithBuffer(x,y,_Assets.GetAsset(AssetName));

}

void Buffer::UpdateWithBuffer(int x, int y, Ressource  * External) {

	int xsize = External->xBufferSize;
	int ysize = External->yBufferSize;
	x -= xsize / 2;
	y -= ysize / 2;
	int xoff = (x < 0) ? -x : 0;
	int yoff = (y < 0) ? -y : 0;
	xsize -= ((x + xoff + xsize) >= SCREEN_HEIGHT) ? (x + xoff + xsize) - SCREEN_HEIGHT : 0;
	ysize -= ((y + yoff + ysize) >= SCREEN_WIDTH) ? (y + yoff + ysize) - SCREEN_WIDTH : 0;
	for (int xIterator = xoff; xIterator < xsize; xIterator++) {

		for (int yIterator = yoff; yIterator < ysize; yIterator++)
		{
			char a;
			a= External->_Buffer[xIterator][yIterator].Char.AsciiChar;
		
		buffer[x + xIterator][y + yIterator].Char.AsciiChar = External->_Buffer[xIterator][yIterator].Char.AsciiChar;
		buffer[x + xIterator][y + yIterator].Attributes =  0x0a;
		ApplyColor(x + xIterator, y + yIterator, External->_stype,a);



		}
		}


	}



void Buffer::ApplyColor(int x, int y, string res, char a) {



	if (res == "Mainscreen") {

		switch (a)
		{

		case 'M':
			buffer[x][y].Attributes = 0x04;
			break;
		case 'H':
			buffer[x][y].Attributes = 0x04;
			break;
		case '0':
			buffer[x][y].Attributes = 0x04;
			break;
		case '/':
			buffer[x][y].Attributes = 0x04;
			break;
		}




	}

	if (res == "player") {

		switch (a)
		{

		case '<':
			buffer[x][y].Attributes = 0x04;
			break;
		case '-':
			buffer[x][y].Attributes = 0x04;
			break;


		case '>':
			buffer[x][y].Attributes = 0x01;
			break;

		case 'X':
			buffer[x][y].Attributes = 0x01;
			break;
		case '=':
			buffer[x][y].Attributes = 0x01;
			break;

		case '*':
			buffer[x][y].Attributes = 0x06;
			break;
		case '[':
			buffer[x][y].Attributes = 0x06;
			break;
		case ']':
			buffer[x][y].Attributes = 0x06;
			break;

		}
	}

		if (res == "target") {

			switch (a)
			{

			case '<':
				buffer[x][y].Attributes = 0x02;
				break;
			case '-':
				buffer[x][y].Attributes = 0x04;
				break;


			case '>':
				buffer[x][y].Attributes = 0x04;
				break;

			case '*':
				buffer[x][y].Attributes = 0x06;
				break;
			case '[':
				buffer[x][y].Attributes = 0x06;
				break;
			case ']':
				buffer[x][y].Attributes = 0x06;
				break;

			}


		}
	
	
	}


void Buffer::MainMenu(string file)
{
	ifstream infile(file, ifstream::in);
	int number_of_lines = 0;
	std::string line;
	int SizeMaxOfLine = 0;
	while (infile.good())
	{
		getline(infile, line);
		if (line.length() > SizeMaxOfLine) {
			SizeMaxOfLine = line.length();
		}
		for (int iterator = 0; iterator < 70; iterator++) {
			char a = line.at(iterator);
			buffer[number_of_lines + 10][iterator + 10].Char.AsciiChar = a;

			switch (a)
			{

			case 'M':
				buffer[number_of_lines + 10][iterator +10].Attributes = 0x0044;
				break;
			case 'H':
				buffer[number_of_lines + 10][iterator + 10].Attributes = 0x44;
				break;
			case '0':
				buffer[number_of_lines + 10][iterator + 10].Attributes = 0x74;
				break;
			}

		
			
		}
		++number_of_lines;
		//cout << line;
	}
	Draw();

	char  chk = getchar();
	PlaySound(TEXT("intro.wav"), NULL, SND_FILENAME || SND_ASYNC);

//	PlaySound(NULL, 0, 0);
	
}
void Buffer::Draw() {
	//memcpy(buffer, buffer, SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(CHAR_INFO));
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
}

void Buffer::DrawText(std::string text, int x, int y, char color) {
	for (int i = 0; i < text.size(); i++)
		CheckAndUpdate(y, x+i, text[i], color);
}

void Buffer::Reset(int color) {
	memset(buffer, color, SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(CHAR_INFO));
}

void Buffer::InitStars() {
	for (int i = 0; i < STARS_NUMBER; i++) {
		starBuffer[i].x = rand() % SCREEN_WIDTH;
		starBuffer[i].y = rand() % SCREEN_HEIGHT;
		starBuffer[i].c = '*';
		starBuffer[i].color = rand() % 0x0F;
	}
}

void Buffer::DrawStars() {
	for (int i = 0; i < STARS_NUMBER; i++)
		Update(starBuffer[i].y, starBuffer[i].x, starBuffer[i].c, starBuffer[i].color);
}

void Buffer::MoveStars(const float x, const float y, float time) {
	starDeltaX += x*time;
	starDeltaX += y*time;
	for (int i = 0; i < STARS_NUMBER; i++) {
		starBuffer[i].x += (int)starDeltaX;
		starBuffer[i].x %= SCREEN_WIDTH;
		starBuffer[i].y += (int)starDeltaY;
		starBuffer[i].y %= SCREEN_HEIGHT;
	}
	starDeltaX -= (int)starDeltaX;
	starDeltaY -= (int)starDeltaY;
}
