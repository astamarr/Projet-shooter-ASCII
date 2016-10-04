// Jeu.cpp : définit le point d'entrée pour l'application console.
//


#include <iostream>;
#include <Windows.h>;
#include <stdlib.h>;

#include "Buffer.h";
#include "NYtimer.h";
using namespace std;


int main()
{
	Buffer * a = new Buffer();
	NYTimer *  timer = new NYTimer();
	timer->start();

	int time = 0;
	while (true) {

		 time = timer->getElapsedMs(true);
		a->Draw();


		
		
	}

}

