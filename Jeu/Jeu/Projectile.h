#pragma once
#include "Objet.h"
class Projectile :
	public Objet
{
private:

public:
<<<<<<< HEAD
	Projectile(int x, int y, float xSpeed = 0.f, float ySpeed = 0.f);
=======
	Projectile(int x=0, int y=0, float xSpeed = 0.f , float ySpeed = 0.f);
>>>>>>> origin/Dev
	~Projectile();

	Projectile(const Projectile& cible);


};

