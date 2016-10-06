// Jeu.cpp : définit le point d'entrée pour l'application console.
//


#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include "Assets.h"
#include "Ressource.h"
#include "Buffer.h"
#include "Objet.h"
#include "Projectile.h"
#include "ObjectVector.h"
#include "NYtimer.h";
using namespace std;


int main()
{
	Buffer a;
	NYTimer timer;
	timer.start();
	Objet o;
	Objet e(20,20,3,2.f);
	float time;
	ObjectVector projectile;
	

	
	Assets   testAssets;
	Assets   testAssets2;
	testAssets.LoadPlayerFromFile("ship.txt");
	testAssets2.LoadPlayerFromFile("ship2.txt");





	while (true) {

		time = timer.getElapsedSeconds(true);
		a.Reset(0x00);
		
		a.UpdateWithBuffer(o.GetY(), o.GetX(), testAssets.Player);
		a.UpdateWithBuffer(20, 20, testAssets2.Player);
		//a.Update(o.GetY(), o.GetX(), 'O', 0x00);
		projectile.Draw(a);

		if (GetAsyncKeyState('Q'))
			o.Move(-1, 0, time);
		if (GetAsyncKeyState('D'))
			o.Move(1, 0, time);
		if (GetAsyncKeyState('S'))
			o.Move(0,1, time);
		if (GetAsyncKeyState('Z'))
			o.Move(0,-1, time);
		if (GetAsyncKeyState(VK_SPACE))
			projectile.AddObject(Projectile(o.GetX(), o.GetY(), 35.f, 0.f));
		o.Update(time);
		projectile.UpdateWithBoundCheck(time);
#ifdef _DEBUG
		//timer.start();
#endif
		a.Draw();
		
	}

}

