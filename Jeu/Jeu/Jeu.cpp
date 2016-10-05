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
	Buffer a;
	NYTimer timer;
	timer.start();
	Objet o;
	float time;
	while (true) {

		time = timer.getElapsedSeconds(true);
		a.Reset(0xC0);
		a.Update(o.GetY(), o.GetX(), 'O', 0x00);

		if (GetAsyncKeyState('Q'))
			o.Move(-1, 0, time);
		if (GetAsyncKeyState('D'))
			o.Move(1, 0, time);
		if (GetAsyncKeyState('S'))
			o.Move(0,1, time);
		if (GetAsyncKeyState('Z'))
			o.Move(0,-1, time);
		o.Update(time);
#ifdef _DEBUG
		//timer.start();
#endif
		a.Draw();
		
	}

}

