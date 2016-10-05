#pragma once
class Objet
{
private:
	int _x=10, _y=10;
	float _maxSpeed;
	float _xSpeed = 0.0f, _ySpeed = 0.0f;
	float _deltaX, _deltaY;

public:
	Objet() : _deltaX(0.f), _deltaY(0.f), _maxSpeed(0.f) {};
	~Objet() {};
	
	void Move(const float x,const float y);

	void Update(const int time);

	int GetX() { return _x; };
	int GetY() { return _y; };




};

