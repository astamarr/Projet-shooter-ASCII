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
		a->Reset(0xC0);
		
		a->Update(o.GetY(), o.GetX(), 'O', 0x00);

		if (GetAsyncKeyState('Q'))
			o.Move(-1, 0);
		if (GetAsyncKeyState('D'))
			o.Move(1, 0);
		if (GetAsyncKeyState('S'))
			o.Move(0,1);
		if (GetAsyncKeyState('Z'))
			o.Move(0,-1);
		o.Update(time);
		a->Draw();
		
	}

}

