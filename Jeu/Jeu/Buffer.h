#pragma once
#include "stdafx.h"
#include "Buffer.h"
#include "stdafx.h";
#include <iostream>;
#include <Windows.h>;
#include <stdlib.h>;
// JE SUIS UN GRIOS COMMENTAIRE
using namespace std;

class Buffer
{
public:

	 static const int SCREEN_WIDTH = 77;
	static const int SCREEN_HEIGHT = 22;
	HANDLE hOutput;
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	COORD dwBufferSize;
	COORD dwBufferCoord;
	SMALL_RECT rcRegion ;





	Buffer();
	~Buffer();

	void Draw();
	void Reset(int color);
	void Update(int x, int y , char c);
	void Update(int x, int y, char c, char color);
	void LoadFromFile(string file);
};

