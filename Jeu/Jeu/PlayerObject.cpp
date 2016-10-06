#include "PlayerObject.h"



PlayerObject::PlayerObject() : arme(WP_SHOTGUN)
{
	

}


PlayerObject::~PlayerObject()
{
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
	arme.Update(time);
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
	if (_x > Buffer::SCREEN_WIDTH-1)
		_x = Buffer::SCREEN_WIDTH-1;
	if (_y > Buffer::SCREEN_HEIGHT-1)
		_y = Buffer::SCREEN_HEIGHT - 1;
}

void PlayerObject::Shoot(ObjectVector& proj) {
	arme.Shoot(proj,_x,_y);
}
