// Jeu.cpp : définit le point d'entrée pour l'application console.
//


#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <random>
#include "Assets.h"
#include "Ressource.h"
#include "Buffer.h"
#include "LevelManager.h"
#include "NYtimer.h";
using namespace std;


int main()
{
	Buffer MainBuffer;
	NYTimer timer;
	timer.start();
	LevelManager level;
	float time;
	
	srand(25);

	
	Assets   testAssets;
	Assets   testAssets2;
	testAssets.LoadPlayerFromFile("ship.txt");
	testAssets.LoadPlayerFromFile("ship2.txt");

	MainBuffer.InitStars();

	

	while (true) {

		time = timer.getElapsedSeconds(true);
		shootTimer += time;
		a.Reset(0x00);
		
		a.Reset(0x00);
		a.DrawStars();
		level.Draw(a);
#ifdef _DEBUG
		//timer.start();
#endif
		a.Draw();

		if (GetAsyncKeyState(VK_ESCAPE))
			break;

		a.MoveStars(-120.f, 0, time);
		level.Update(time);
		level.Event(time);
		
	}

}

