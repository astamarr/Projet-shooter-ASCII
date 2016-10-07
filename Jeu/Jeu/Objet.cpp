#include "Objet.h"
#include "Assets.h"

Objet::Objet(int x, int y, int collisionRadius, float maxSpeed, float maxDec, float maxAcc) {
	_x = x;
	_y = y;
	_collisionRadius = collisionRadius;
	_maxSpeed = maxSpeed;
	_maxDec = maxDec;
	_maxAcc = maxAcc;
	_exist = true;
}

Objet::Objet(const Objet& cible) {
	_x = cible._x;
	_y = cible._y;
	_maxAcc = cible._maxAcc;
	_maxDec = cible._maxDec;
	_maxSpeed = cible._maxSpeed;
	_xSpeed = cible._xSpeed;
	_ySpeed = cible._ySpeed;
	_deltaX = cible._deltaX;
	_deltaY = cible._deltaY;
	_collisionRadius = cible._collisionRadius;
	_exist=cible._exist;
}

void Objet::Move(const float x, const float y, const float time) {

	_xSpeed += x * time * _maxAcc * _maxSpeed;
	_ySpeed += y * time * _maxAcc * _maxSpeed;
	if (_xSpeed > _maxSpeed) _xSpeed = _maxSpeed;
	if (_xSpeed < -_maxSpeed) _xSpeed = -_maxSpeed;
	if (_ySpeed > _maxSpeed) _ySpeed = _maxSpeed;
	if (_ySpeed < -_maxSpeed)_ySpeed = -_maxSpeed;
};

void Objet::Draw(Buffer& buffer) {
	
}

void Objet::Update(const float time) {
	float movex = _xSpeed*time;
	float movey = _ySpeed*time;
	_deltaX += movex;
	_deltaY += movey;
	_x += (int)_deltaX;
	_y += (int)_deltaY;
	_deltaX -= (int)_deltaX;
	_deltaY -= (int)_deltaY;
	float deltaSpeed = _xSpeed * time * _maxDec;
	if (std::abs(deltaSpeed) > abs(_xSpeed)) {
		_xSpeed = 0;
	}
	else {
		_xSpeed -= deltaSpeed;
	}
	deltaSpeed = _ySpeed * time * _maxDec;
	if (std::abs(deltaSpeed) > abs(_ySpeed)) {
		_ySpeed = 0;
	}
	else {
		_ySpeed -= deltaSpeed;
	}

}

bool Objet::Collide(const Objet& cible) {
	if (abs(cible._x - _x) < (cible._collisionRadius + _collisionRadius) &&
		abs(cible._y - _y) < (cible._collisionRadius + _collisionRadius))
		return true;
	return false;
}
