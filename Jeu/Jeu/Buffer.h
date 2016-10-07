#pragma once
#include "Ressource.h"
#include "Assets.h"
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
using namespace std;
// JE SUIS UN GRIOS COMMENTAIRE
class Assets;
typedef struct Etoile {
	int x;
	int y;
	char c;
	char color;
} Etoile;

class Buffer
{
public:

	static const int SCREEN_WIDTH = 250;
	static const int SCREEN_HEIGHT = 70;
	static const int STARS_NUMBER = 50;
	HANDLE hOutput;
	CHAR_INFO buffer[SCREEN_HEIGHT][SCREEN_WIDTH];
	COORD dwBufferCoord;
	Assets _Assets;


	SMALL_RECT rcRegion ;
	COORD dwBufferSize;

	Etoile starBuffer[STARS_NUMBER];
	float starTimer = 0;
	float starDeltaX = 0.f;
	float starDeltaY = 0.f;



	int _PlayerLife;



	Buffer();
	~Buffer();

	void Draw();
	void Reset(int color);
	void Update(int x, int y , char c);
	void Update(int x, int y, char c, char color);
	void CheckAndUpdate(int x, int y, char c, char color);
	void UpdateFromAsset(int x, int y, string Assetname, int vie);
	void UpdateFromAsset(int x, int y, string Assetname);

	void UpdateWithBuffer(int x, int y, Ressource *  test);
	void ApplyColor(int x, int y, string restype, char a);
	void MainMenu(std::string file);

	void InitStars();
	void DrawStars();
	void DrawText(std::string text, int x, int y, char color);
	void MoveStars(const float x, const float y, float time);

	
};

