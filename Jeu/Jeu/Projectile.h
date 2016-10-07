#pragma once
#include "Objet.h"

class Projectile :
	public Objet
{
private:
	int _damage = 1;
public:

	Projectile() {};
	Projectile(int x, int y, float xSpeed = 0.f, float ySpeed = 0.f, int damage=1);


	~Projectile();
	

	//Projectile(int x=0, int y=0, float xSpeed = 0.f , float ySpeed = 0.f);



	Projectile(const Projectile& cible);
	
	bool Collide(Objet& obj);


};

