#pragma once
#include "Objet.h"
#include "ObjectVector.h"
#include "Buffer.h"
#include "Projectile.h"
#include "Arme.h"
class PlayerObject :
	public Objet
{
private:
	Arme arme;
//	Projectile _projectileType;
public:
	PlayerObject();
	~PlayerObject();

	bool ReadyToShoot();
	const Projectile& Shoot();
	void Update(float time);
	void Shoot(ObjectVector& proj);
};

