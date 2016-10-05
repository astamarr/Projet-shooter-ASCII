// Jeu.cpp : définit le point d'entrée pour l'application console.
//


#include <iostream>;
#include <Windows.h>;
#include <stdlib.h>;
#include <io.h>
#include <fcntl.h>
#include "Buffer.h";
#include "Objet.h"
#include "NYtimer.h";
using namespace std;


int main()
{
	Buffer * a = new Buffer();
	NYTimer *  timer = new NYTimer();
	timer->start();
	Objet o;
	int time = 0;
	while (true) {

		time = timer->getElapsedMs(true);
		a->Reset();
		
		a->Update(o.GetY()/100, o.GetX()/100, 'O', 0x0F);

		if (GetAsyncKeyState('Q'))
			o.Move(-50*(time/10.0), 0);
		if (GetAsyncKeyState('D'))
			o.Move(50*(time/10.0), 0);
		if (GetAsyncKeyState('S'))
			o.Move(0,50 * (time / 10.0));
		if (GetAsyncKeyState('Z'))
			o.Move(0,-50 * (time / 10.0));

		a->Draw();
		
	}

}

