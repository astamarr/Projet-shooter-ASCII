#include "Buffer.h";
#pragma warning (disable : 4996)
#pragma comment( lib, "winmm" )
#include <stdio.h>;
#include <sstream>;
#include <Windows.h>;
#include <string>;
#include <fstream>;
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


void Buffer::LoadFromFile(string file)
{
	ifstream infile(file, ifstream::in);
	int number_of_lines = 0;
	string line;
	int SizeMaxOfLine = 0;
	while (infile.good())
	{
		getline(infile, line);
		if (line.length() > SizeMaxOfLine) {
			SizeMaxOfLine = line.length();
		}
		for (int iterator = 0; iterator < SCREEN_WIDTH; iterator++) {
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