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
/*
const Projectile& PlayerObject::Shoot() {
	_lastShoot = 0.f;
	return _projectileType;
}
*/
void PlayerObject::Update(float time)
{
	Objet::Update(time);
	_lastShoot += time;
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
	if (_x > Buffer::SCREEN_WIDTH-1)
		_x = Buffer::SCREEN_WIDTH-1;
	if (_y > Buffer::SCREEN_HEIGHT-1)
		_y = Buffer::SCREEN_HEIGHT - 1;
}
