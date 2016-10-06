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
	LoadFromFile("test1.txt");
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

void Buffer::UpdateWithBuffer(int x, int y, Ressource  * External) {

	int xsize = External->xBufferSize;
	int ysize = External->yBufferSize;
	x -= xsize / 2;
	y -= ysize / 2;

	for (int xIterator = 0; xIterator < xsize; xIterator++) {

		for (int yIterator = 0; yIterator < ysize; yIterator++)
		{
			char a;
			a= External->_Buffer[xIterator][yIterator].Char.AsciiChar;
		
		buffer[x + xIterator][y + yIterator].Char.AsciiChar = External->_Buffer[xIterator][yIterator].Char.AsciiChar;
		buffer[x + xIterator][y + yIterator].Attributes =  0x0a;
		}


	}




}


void Buffer::LoadFromFile(string file)
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
			buffer[number_of_lines][iterator].Char.AsciiChar = a;
			buffer[number_of_lines][iterator].Attributes = 0x4a;
		}
		++number_of_lines;
		//cout << line;
	}
	Draw();
	//PlaySound(TEXT("test2.wav"), NULL, SND_FILENAME);
	cin >> line;
}
void Buffer::Draw() {
	//memcpy(buffer, buffer, SCREEN_WIDTH*SCREEN_HEIGHT * sizeof(CHAR_INFO));
	WriteConsoleOutput(hOutput, (CHAR_INFO *)buffer, dwBufferSize,
		dwBufferCoord, &rcRegion);
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
