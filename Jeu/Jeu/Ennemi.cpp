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
		_arme.SetAngle(180.f);
		_collisionRadius = 1;
		_maxSpeed = 50.f;
		_maxAcc = 10.f;
		_maxDec = 10.f;
		_life = 1;
		LinkedRes = "target";
		break;
	case EN_RUNNER:
		_arme.SetType(WP_SHOTGUN);
		_arme.SetAngle(180.f);
		_collisionRadius = 1;
		_maxSpeed = 100.f;
		LinkedRes = "runner";
		_maxAcc = 25.f;
		_maxDec = 25.f;
		_life = 1;
		break;
	default:
		break;
	}
}

void Ennemi::Update(float time) {
	Objet::Update(time);
	_arme.Update(time);
	_invulnerabily += time;
	_timer += time;
	_continuousTimer += time;
	if (_life <= 0)
		Kill();
}

void Ennemi::Action(ProjectileVector& proj, float time) {
	switch (_type) {
	case EN_BASIC:
		Move(-1, 0, time);
		if (_timer > 0.3f) {
			_arme.MoveAngle(rand()%10-5);
			Shoot(proj);
			_timer = 0;
		}
		break;
	case EN_RUNNER:
		if (_continuousTimer < 5.f) {
			Move(-0.2, 0, time);
			if (_timer > 1.7f) {
				Shoot(proj);
				_timer = 0;
			}
		}
		else {
			Move(-1, 0, time);
		}
	default:
		break;
	}
}




void Ennemi::Draw(Buffer& buffer) {
	buffer.UpdateFromAsset(_y, _x, LinkedRes);
}

void Ennemi::Alive() {
	Objet::Alive();
	_continuousTimer = 0.f;
}


