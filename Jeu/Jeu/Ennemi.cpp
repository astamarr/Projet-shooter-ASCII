#include "Ennemi.h"



Ennemi::Ennemi() : PlayerObject()
{
}

Ennemi::Ennemi(int type, int x, int y) : PlayerObject(), _type(type) {
	SetPosition(x, y);
	Alive();
	Set();
}

Ennemi::~Ennemi()
{
}

void Ennemi::Set() {
	switch (_type) {
	case EN_BASIC:
		_collisionRadius = 1;
		_maxSpeed = 50.f;
		_maxAcc = 10.f;
		_maxDec = 10.f;
		_life = 1;
		break;

	default:
		break;
	}
}

void Ennemi::Update(float time) {
	Objet::Update(time);
	_arme.Update(time);
	if (_life <= 0)
		Kill();
}

void Ennemi::Action(ProjectileVector& proj, float time) {
	switch (_type) {
	case EN_BASIC:
		Move(-1, 0, time);
		Shoot(proj);
		break;
	default:
		break;
	}
}




void Ennemi::Draw(Buffer& buffer) {
	buffer.UpdateFromAsset(_y, _x, "target");
}


