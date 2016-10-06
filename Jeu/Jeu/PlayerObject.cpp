#include "PlayerObject.h"



PlayerObject::PlayerObject() : _arme(WP_SHOTGUN)
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
	_arme.Update(time);
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
	if (_x > Buffer::SCREEN_WIDTH-1)
		_x = Buffer::SCREEN_WIDTH-1;
	if (_y > Buffer::SCREEN_HEIGHT-1)
		_y = Buffer::SCREEN_HEIGHT - 1;
}

void PlayerObject::Shoot(ProjectileVector& proj) {
	_arme.Shoot(proj,_x,_y);
}

void PlayerObject::Draw(Buffer& buffer) {
	buffer.Update( _y, _x, 'X', 0x0F);
}
