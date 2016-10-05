#pragma once

#include <cmath>

class Objet
{
protected:
	int _x=10, _y=10;
	float _maxAcc = 2.f;
	float _maxDec = 1.f;
	float _maxSpeed;
	float _xSpeed = 0.0f, _ySpeed = 0.0f;
	float _deltaX, _deltaY;
	int _collisionRadius;
	bool _exist=false;

public:
	Objet() : _deltaX(0.f), _deltaY(0.f), _maxSpeed(50.f) {};
	Objet(int x, int y, int collisionRadius, float maxSpeed, float maxDec=0.f, float maxAcc=0.f);
	Objet(const Objet& cible);
	~Objet() {};
	
	void Move(const float x,const float y, const float time);

	void Update(const float time);

	void SetPosition(const int x, const int y) { _x = x; _y = y; };
	void MovePosition(const int x, const int y) { _x += x; _y += y; };

	int GetX() { return _x; };
	int GetY() { return _y; };

	bool Collide(const Objet& cible);

	void Alive() { _exist = true; };
	void Kill() { _exist = false; };
	bool isAlive() { return _exist; };
};

