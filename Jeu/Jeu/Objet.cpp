#include "Objet.h"

void Objet::Move(const float x, const float y) {
	if(_xSpeed<=2.0f && _xSpeed>=-2.f)
		_xSpeed += x;
	if(_ySpeed<=2.0f && _ySpeed>=-2.f)
		_ySpeed += y;
};

void Objet::Update(const int time) {
	float movex = (_xSpeed*time)/1000.f;
	float movey = (_ySpeed*time)/1000.f;
	_deltaX += movex;
	_deltaY += movey;
	_x += (int)_deltaX;
	_y += (int)_deltaY;
	_deltaX -= (int)_deltaX;
	_deltaY -= (int)_deltaY;
}

