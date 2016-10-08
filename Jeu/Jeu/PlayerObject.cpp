#include "PlayerObject.h"



PlayerObject::PlayerObject() : _arme(WP_FASTONE)
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
	_rollingTimer += time;
	_invulnerabily += time;
	if (_x < 0)
		_x = 0;
	if (_y < 0)
		_y = 0;
	if (_x >= Buffer::SCREEN_WIDTH)
		_x = Buffer::SCREEN_WIDTH-1;
	if (_y >= Buffer::SCREEN_HEIGHT)
		_y = Buffer::SCREEN_HEIGHT - 1;
}

void PlayerObject::Shoot(ProjectileVector& proj) {
	_arme.Shoot(proj,_x,_y);
}

void PlayerObject::Draw(Buffer& buffer) {
	if((_invulnerabily>1.5f) || ((int)(_invulnerabily*100)%50)>25)
		buffer.UpdateFromAsset( _y, _x, "player", _life);
}

void PlayerObject::GetHit(int damage) {
	if (_invulnerabily < 1.5f)
		return;
	_life -= damage;
	if (_life <= 0)
		Kill();
	_invulnerabily = 0.f;
}

void PlayerObject::RollWeapon() {
	if (_rollingTimer > 0.5f) {
		_arme.RollType(); 
		_rollingTimer = 0;
	}
}