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
#include "Objet.h"
#include "PlayerObject.h"
#include "Projectile.h"
#include "ObjectVector.h"
#include "NYtimer.h";
using namespace std;


int main()
{
	Buffer MainBuffer;
	NYTimer timer;
	timer.start();
	PlayerObject o;
	Objet méchant;
	ObjectVector enemies;
	float time;
	float shootTimer = 0;
	ObjectVector projectile;
	srand(25);

	
	Assets   testAssets;
	Assets   testAssets2;
	testAssets.LoadPlayerFromFile("ship.txt");
	testAssets.LoadPlayerFromFile("ship2.txt");

	MainBuffer.InitStars();



	while (true) {

		time = timer.getElapsedSeconds(true);
		shootTimer += time;
		MainBuffer.Reset(0x00);
		
		MainBuffer.DrawStars();
		//a.Update(o.GetY(), o.GetX(), 'O', 0x00);
		projectile.Draw(MainBuffer);


		MainBuffer.UpdateWithBuffer(o.GetY(), o.GetX(), testAssets.GetAsset("player"));
		MainBuffer.UpdateWithBuffer(10, 50, testAssets.GetAsset("target"));


		enemies.Draw(MainBuffer);

		if (GetAsyncKeyState('Q'))
			o.Move(-1, 0, time);
		if (GetAsyncKeyState('D'))
			o.Move(1, 0, time);
		if (GetAsyncKeyState('S'))
			o.Move(0,1, time);
		if (GetAsyncKeyState('Z'))
			o.Move(0,-1, time);
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		if (GetAsyncKeyState(VK_SPACE) && shootTimer > .05f) {
			o.Shoot(projectile);
		}
		o.Update(time);
		enemies.Update(time);
		projectile.UpdateWithBoundCheck(time);

		MainBuffer.MoveStars(-120.f, 0, time);

#ifdef _DEBUG
		//timer.start();
#endif
		MainBuffer.Draw();
		
	}

}

