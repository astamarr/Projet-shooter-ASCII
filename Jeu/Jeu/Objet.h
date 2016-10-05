#pragma once
class Objet
{
private:
	int _x=10, _y=10;
	double _vx=0, _vy=0;
public:
	Objet() {};
	~Objet() {};
	
	void Move(double x, double y) {
		_vx = (x-_vx)/2; _vy = ( y-_vy)/2;
	};

	int GetX() { return _x; };
	int GetY() { return _y; };

	void Update() { _x += _vx; _y += _vy; };



};

