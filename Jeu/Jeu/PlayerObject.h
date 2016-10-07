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
	float _rollingTimer=0;
	float _invulnerabily = 0;

public:
	PlayerObject();
	~PlayerObject();


	void Update(float time);
	void Shoot(ProjectileVector& proj);
	void Draw(Buffer& buffer);
	void GetHit(int damage);
	void SetLife(int life) { _life = life; };

	void RollWeapon();
	const std::string GetWeaponName() { return _arme.GetName(); };
};

