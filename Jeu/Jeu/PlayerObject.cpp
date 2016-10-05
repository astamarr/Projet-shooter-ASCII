#include "PlayerObject.h"



PlayerObject::PlayerObject()
{
	
	_shootTime = 1.f;
}


PlayerObject::~PlayerObject()
{
}

bool PlayerObject::ReadyToShoot() {
	return _lastShoot > _shootTime;
}

const Projectile& PlayerObject::Shoot() {
	_lastShoot = 0.f;
	//return _projectileType;
}

void PlayerObject::Update(float time)
{
	Objet::Update(time);
	_lastShoot += time;
}
