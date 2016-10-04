#pragma once
class Objet
{
public:
	Objet();
	~Objet();
	mabite
	void Move(double x, double y) {
		_vx = x; _vy = y;
	};




private:
	int _x, _y;
	double _vx, _vy;

};

