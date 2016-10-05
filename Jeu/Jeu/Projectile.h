#pragma once
#include "Objet.h"
class Projectile :
	public Objet
{
private:

public:

	Projectile(int x, int y, float xSpeed = 0.f, float ySpeed = 0.f);

	Projectile(int x=0, int y=0, float xSpeed = 0.f , float ySpeed = 0.f);

	~Projectile();

	Projectile(const Projectile& cible);


};

