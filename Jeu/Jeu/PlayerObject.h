#pragma once
#include "Objet.h"
#include "ProjectileVector.h"
#include "Buffer.h"
#include "Projectile.h"
#include "Arme.h"
class PlayerObject :
	public Objet
{
protected:
	Arme _arme;
	int _life;

public:
	PlayerObject();
	~PlayerObject();


	void Update(float time);
	void Shoot(ProjectileVector& proj);
	void Draw(Buffer& buffer);
	void GetHit(int damage) { _life -= damage; };
};

