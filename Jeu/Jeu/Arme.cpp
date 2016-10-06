#include "Arme.h"



Arme::Arme(unsigned int type)
{
	_type = type;
}


Arme::~Arme()
{
}

void Arme::Update(float time) {
	_timer += time;
}

void Arme::Shoot(ObjectVector& projBuffer, int x, int y) {
	switch (_type) {
	case WP_SHOTGUN : 
		if (_timer > .3f) {
			projBuffer.AddObject(Projectile(x, y, 70.f, 25.f));
			projBuffer.AddObject(Projectile(x, y, 70.f, 15.f));
			projBuffer.AddObject(Projectile(x, y, 70.f, 5.f));
			projBuffer.AddObject(Projectile(x, y, 70.f, 0.f));
			projBuffer.AddObject(Projectile(x, y, 70.f, -5.f));
			projBuffer.AddObject(Projectile(x, y, 70.f, -15.f));
			projBuffer.AddObject(Projectile(x, y, 70.f, -25.f));
			ResetTimer();
		}
		break;

	case WP_FASTONE:
		if (_timer > .05f) {
			if(_state==0)
				projBuffer.AddObject(Projectile(x, y-1, 90.f, 0));
			else
				projBuffer.AddObject(Projectile(x, y+1, 90.f, 0));
			_state++;
			_state %= 2;
			ResetTimer();
		}
	default:
		break;
	}
}
