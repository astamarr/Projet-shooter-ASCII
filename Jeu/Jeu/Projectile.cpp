#include "Projectile.h"



Projectile::Projectile(int x, int y, float xSpeed, float ySpeed, int damage)
{
	_x = x;
	_y = y;
	_xSpeed = xSpeed;
	_ySpeed = ySpeed;
	_maxDec = 0.f;
	_collisionRadius = 1;
	_damage = damage;
}


Projectile::~Projectile()
{
}

Projectile::Projectile(const Projectile& cible) : Objet(cible){
	
}

bool Projectile::Collide(Objet& obj) {
	if (Objet::Collide(obj)) {
 		obj.GetHit(_damage);
		Kill();
		return true;
	}
	return false;
}

void Projectile::Draw(Buffer &buffer) {
	buffer.CheckAndUpdate(_y, _x, '-', 0xEC);
}
