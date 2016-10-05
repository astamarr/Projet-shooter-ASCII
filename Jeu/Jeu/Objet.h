#pragma once
class Objet
{
private:
	int _x=10, _y=10;

public:
	Objet() {};
	~Objet() {};
	
	void Move(int x, int y) {
		_x += x; _y += y;
	};

	int GetX() { return _x; };
	int GetY() { return _y; };




};

