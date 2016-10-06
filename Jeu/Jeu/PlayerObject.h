#pragma once
#include "Objet.h"
#include "Buffer.h"
#include "Projectile.h"
class PlayerObject :
	public Objet
{
private:
	float _shootTime;
	float _lastShoot;
//	Projectile _projectileType;
public:
	PlayerObject();
	~PlayerObject();

	bool ReadyToShoot();
	const Projectile& Shoot();
	void Update(float time);
};

