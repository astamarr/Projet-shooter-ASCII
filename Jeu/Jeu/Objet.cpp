#include "Objet.h"

void Objet::Move(const float x, const float y, const float time) {
	_xSpeed += x * time * _maxSpeed;
	_ySpeed += y * time * _maxSpeed;
	if (_xSpeed > _maxSpeed) _xSpeed = _maxSpeed;
	if (_xSpeed < -_maxSpeed) _xSpeed = -_maxSpeed;
	if (_ySpeed > _maxSpeed) _ySpeed = _maxSpeed;
	if (_ySpeed < -_maxSpeed)_ySpeed = -_maxSpeed;
};

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

