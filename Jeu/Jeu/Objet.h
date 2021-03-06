#pragma once

#include <cmath>
#include "Buffer.h"

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
	virtual void Draw(Buffer& buffer);

	void SetPosition(const int x, const int y) { _x = x; _y = y; };
	void MovePosition(const int x, const int y) { _x += x; _y += y; };

	void SetMaxSpeed(float speed) { _maxSpeed = speed; };
	void SetXSpeed(float speed) { _xSpeed = speed; };
	void SetYSpeed(float speed) { _ySpeed = speed; };
	void SetMaxAcc(float acc) { _maxAcc = acc; };
	void SetMaxDec(float dec) { _maxDec = dec; };

	int GetX() { return _x; };
	int GetY() { return _y; };

	bool Collide(const Objet& cible);
	virtual void GetHit(int damage) {};

	virtual void Alive() { _exist = true; };
	void Kill() { _exist = false; };
	bool isAlive() { return _exist; };
};

