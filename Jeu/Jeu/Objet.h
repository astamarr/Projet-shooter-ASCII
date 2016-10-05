#pragma once

#include <cmath>

class Objet
{
protected:
	int _x=10, _y=10;
	float _maxAcc = 1.f;
	float _maxDec = 2.f;
	float _maxSpeed;
	float _xSpeed = 0.0f, _ySpeed = 0.0f;
	float _deltaX, _deltaY;

public:
	Objet() : _deltaX(0.f), _deltaY(0.f), _maxSpeed(50.f) {};
	~Objet() {};
	
	void Move(const float x,const float y, const float time);

	void Update(const float time);

	int GetX() { return _x; };
	int GetY() { return _y; };




};

