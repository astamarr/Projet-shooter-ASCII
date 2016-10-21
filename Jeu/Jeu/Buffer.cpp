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
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	dwBufferSize = { SCREEN_WIDTH,SCREEN_HEIGHT };
	dwBufferCoord = { 0, 0 };
	rcRegion = { 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1 };
	ReadConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,dwBufferCoord, &rcRegion);
 



	SetConsoleScreenBufferSize(hOutput, dwBufferSize);
	
	
	
	
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	
	_Assets.LoadPlayerFromFile("test1.txt");
	_Assets.LoadPlayerFromFile("ship.txt");
	_Assets.LoadPlayerFromFile("ship2.txt");
	_Assets.LoadPlayerFromFile("ship3.txt");
	_Assets.LoadPlayerFromFile("gameover.txt");
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

void Buffer::UpdateFromAsset(int x, int y, string AssetName, int lifepoints) {

	UpdateWithBuffer(x,y,_Assets.GetAsset(AssetName));
	_PlayerLife = lifepoints;


}

void Buffer::UpdateFromAsset(int x, int y, string AssetName) {

	UpdateWithBuffer(x, y, _Assets.GetAsset(AssetName));
	

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
			if (a == ' ') continue;
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
			if (_PlayerLife >= 3)
			{
				buffer[x][y].Attributes = 0x22;
				break;

			}
			else if (_PlayerLife == 2) {
				buffer[x][y].Attributes = 0x66;
				break;
			}

			else {
				buffer[x][y].Attributes = 0x44;
				break;
			}
	
		case '[':
			buffer[x][y].Attributes = 0x06;
			break;
		case ']':
			buffer[x][y].Attributes = 0x06;
			break;

		}
	}

		if (res == "target" ||res == "runner" ) {

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
				buffer[x][y].Attributes = 0x66;
				break;
			case '[':
				buffer[x][y].Attributes = 0x01;
				break;
			case ']':
				buffer[x][y].Attributes = 0x01;
				break;

			}


		}
	
	
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
		starBuffer[i].distance = (rand() % 1000)/500.f +1;
		if(starBuffer[i].distance>2.f)
			starBuffer[i].color = 0x07;
		else
			starBuffer[i].color = 0x0F;
		starBuffer[i].deltaX = 0.f;
		starBuffer[i].deltaY = 0.f;
	}
}

void Buffer::DrawStars() {
	for (int i = 0; i < STARS_NUMBER; i++)
		Update(starBuffer[i].y, starBuffer[i].x, starBuffer[i].c, starBuffer[i].color);
}

void Buffer::DrawWarp(float speed) {
	int line_size = speed/50.f+1;
	for (int i = 0; i < STARS_NUMBER; i++) {
		int size = (starBuffer[i].x +line_size > SCREEN_WIDTH) ? SCREEN_WIDTH - starBuffer[i].x : line_size;
		for (int j = 0; j < size; j++)
			Update(starBuffer[i].y, starBuffer[i].x + j, starBuffer[i].c, starBuffer[i].color);
	}
}

void Buffer::MoveStars(const float x, const float y, float time) {
	starDeltaX += x*time;
	starDeltaX += y*time;
	Etoile *current;
	for (int i = 0; i < STARS_NUMBER; i++) {
		current = &(starBuffer[i]);
		current->deltaX += (x*time) / current->distance;
		current->deltaY += (y*time) / current->distance;
		current->x += (int)current->deltaX;
		if (starBuffer[i].x < 0) {
			starBuffer[i].x = SCREEN_WIDTH+starBuffer[i].x;
			starBuffer[i].y = rand() % SCREEN_HEIGHT;
		}
		current->y += (int)current->deltaY;
		current->y %= SCREEN_HEIGHT;
		current->deltaX -= (int)current->deltaX;
		current->deltaY -= (int)current->deltaY;
	}
	starDeltaX -= (int)starDeltaX;
	starDeltaY -= (int)starDeltaY;
}
