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
	Objet f(30, 30, 3, 2.f);
	float time;
	ObjectVector projectile;
	

	
	Assets   testAssets;

	testAssets.LoadPlayerFromFile("ship.txt");
	testAssets.LoadPlayerFromFile("ship2.txt");





	while (true) {

		time = timer.getElapsedSeconds(true);
		a.Reset(0x00);
		
		a.UpdateWithBuffer(o.GetY(), o.GetX(), testAssets.GetAsset("player"));
		if(e.isAlive())
			a.UpdateWithBuffer(e.GetY(), e.GetX(), testAssets.GetAsset("target"));
		a.UpdateWithBuffer(f.GetY(), f.GetX(), testAssets.GetAsset("target"));
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
		if (GetAsyncKeyState(VK_ESCAPE))
			break;
		if (GetAsyncKeyState(VK_SPACE))
			projectile.AddObject(Projectile(o.GetX(), o.GetY(), 70.f, 0.f));
		o.Update(time);
		//e.Update(time);
		if (projectile.Collide(e))
			e.Kill();
		projectile.UpdateWithBoundCheck(time);

#ifdef _DEBUG
		//timer.start();
#endif
		a.Draw();
		
	}

}

