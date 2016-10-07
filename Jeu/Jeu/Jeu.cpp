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

	

	float time;
	
	srand(25);

	
	Assets testAssets;
	testAssets.LoadPlayerFromFile("ship.txt");
	testAssets.LoadPlayerFromFile("ship2.txt");

	LevelManager level(testAssets);
	
	MainBuffer.InitStars();

	

	while (true) {

		time = timer.getElapsedSeconds(true);

		MainBuffer.Reset(0x00);
		
		MainBuffer.DrawStars();
		level.Draw(MainBuffer);
		MainBuffer.DrawText(std::to_string((float)(1/time)),0, 0, 0x0F);
		MainBuffer.Draw();


		//MainBuffer.UpdateWithBuffer(o.GetY(), o.GetX(), testAssets.GetAsset("player"));
		//MainBuffer.UpdateWithBuffer(8, 10, testAssets.GetAsset("target"));




		if (GetAsyncKeyState(VK_ESCAPE))
			break;


		MainBuffer.MoveStars(-120.f, 0, time);
		level.Update(time);
		level.Event(time);

		

		
	}

}

