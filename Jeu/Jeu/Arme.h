#pragma once
#include "ProjectileVector.h"
#include "Projectile.h"

#define WP_SHOTGUN 0
#define WP_FASTONE 1

class Arme
{
private:
	float angle;
	unsigned int _type;
	float _timer=0.f;
	int _state = 0;


public:
	Arme(unsigned int type);
	~Arme();

	void Update(float time);
	void Shoot(ProjectileVector& projBuffer, int x, int y);
	void ResetTimer() { _timer = 0.f; };
};

