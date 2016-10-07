#pragma once
#include "ProjectileVector.h"
#include "Projectile.h"

#define WP_NUMBER  3
#define WP_SHOTGUN 0
#define WP_FASTONE 1
#define WP_LASER   2

#define PI 3.14159265

class Arme
{
private:
	float _angle;
	float _speed;
	unsigned int _type;
	float _timer=0.f;
	int _state = 0;
	std::string _name;


public:
	Arme(unsigned int type);
	~Arme();

	void SetType(int type);
	void RollType();
	void Update(float time);
	void SetAngle(float angle) { _angle = angle*PI/180; };
	void Shoot(ProjectileVector& projBuffer, int x, int y);
	void ShootProjectile(ProjectileVector& proj, int x, int y, float angleOffset);
	void ResetTimer() { _timer = 0.f; };

	const std::string &GetName() { return _name; };
};

