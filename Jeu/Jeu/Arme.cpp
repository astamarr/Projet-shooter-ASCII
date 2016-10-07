#include "Arme.h"
#include <cmath>


Arme::Arme(unsigned int type)
{
	SetType(type);
	_angle = 0;
	
}


Arme::~Arme()
{
}

void Arme::SetType(int type) {
	_type = type;
	switch (_type) {
	case WP_SHOTGUN:
		_speed = 70.f;
		break;
	case WP_FASTONE:
		_speed = 100.f;
		break;
	case WP_LASER:
		_speed = 200.f;
		break;
	default:
		break;
	}
}

void Arme::Update(float time) {
	_timer += time;
}

void Arme::Shoot(ProjectileVector& projBuffer, int x, int y) {
	switch (_type) {
	case WP_SHOTGUN : 
		if (_timer > .9f) {
			ShootProjectile(projBuffer, x, y, 0.05f);
			ShootProjectile(projBuffer, x, y, 0.025f);
			ShootProjectile(projBuffer, x, y, 0.f);
			ShootProjectile(projBuffer, x, y, -0.025f);
			ShootProjectile(projBuffer, x, y, -0.05f);
			ResetTimer();
		}
		break;

	case WP_FASTONE:
		if (_timer > .05f) {
			if(_state==0)
				ShootProjectile(projBuffer, x, y-sin(_angle+1.5f), 0.f);
			else
				ShootProjectile(projBuffer, x, y+sin(_angle+1.5f), 0.f);
			_state++;
			_state %= 2;
			ResetTimer();
		}
		break;

	case WP_LASER:
		if (_timer > 2.5f) {
			ShootProjectile(projBuffer, x, y, 0.f);
			ResetTimer();
		}
		break;

	default:
		projBuffer.AddObject(Projectile(x, y - 1, -90.f, 0));
		break;
	}
}

void Arme::ShootProjectile(ProjectileVector& proj, int x, int y, float angleOffset) {
	proj.AddObject(Projectile(x, y, _speed*cos(_angle - angleOffset), _speed*sin(_angle - angleOffset)));
}
