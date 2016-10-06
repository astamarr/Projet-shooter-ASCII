#include "Projectile.h"



Projectile::Projectile(int x, int y, float xSpeed, float ySpeed)
{
	_x = x;
	_y = y;
	_xSpeed = xSpeed;
	_ySpeed = ySpeed;
	_maxDec = 0.f;
	_collisionRadius = 1;
}


Projectile::~Projectile()
{
}

Projectile::Projectile(const Projectile& cible) : Objet(cible){
	
}
