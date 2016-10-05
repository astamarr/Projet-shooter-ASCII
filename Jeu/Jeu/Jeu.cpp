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
	_setmode(_fileno(stdout), _O_U16TEXT);
	Buffer * a = new Buffer();
	NYTimer *  timer = new NYTimer();
	timer->start();
	Objet o;
	int time = 0;
	while (true) {

		time = timer->getElapsedMs(true);
		//a->Reset();
		a->Draw();
		a->UpdateUni(o.GetX(), o.GetY(), 0x264, 0x0F);

		if (GetAsyncKeyState('Q'))
			break;
		if (GetAsyncKeyState('D'))
			o.Move(5, 0);
		o.Update();
		
		
	}

}

