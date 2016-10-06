#pragma once
#include "Ressource.h";

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
// JE SUIS UN GRIOS COMMENTAIRE


class Buffer
{
public:

	 static const int SCREEN_WIDTH = 200;
	static const int SCREEN_HEIGHT = 200;
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
	void UpdateWithBuffer(int x, int y, Ressource *  test);
	void LoadFromFile(std::string file);
};

