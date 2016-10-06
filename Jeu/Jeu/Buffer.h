#pragma once
#include "Ressource.h"

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
using namespace std;
// JE SUIS UN GRIOS COMMENTAIRE

typedef struct Etoile {
	int x;
	int y;
	char c;
	char color;
} Etoile;

class Buffer
{
public:

	static const int SCREEN_WIDTH = 200;
	static const int SCREEN_HEIGHT = 200;
	static const int STARS_NUMBER = 200;
	HANDLE hOutput;
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	COORD dwBufferCoord;
	SMALL_RECT rcRegion ;
	COORD dwBufferSize;

	Etoile starBuffer[STARS_NUMBER];
	float starTimer = 0;
	float starDeltaX = 0.f;
	float starDeltaY = 0.f;





	Buffer();
	~Buffer();

	void Draw();
	void Reset(int color);
	void Update(int x, int y , char c);
	void Update(int x, int y, char c, char color);
	void UpdateWithBuffer(int x, int y, Ressource *  test);
	void LoadFromFile(std::string file);

	void InitStars();
	void DrawStars();
	void MoveStars(const float x, const float y, float time);

	
};

