#pragma once

#include <vector>
#include <Windows.h>
#include "Buffer.h"
#include "EnnemiGenerator.h"
#include "ProjectileVector.h"

class LevelManager
{
private:
	EnnemiGenerator ennemis;
	ProjectileVector playerProjectile;
	ProjectileVector ennemiProjectile;
	PlayerObject player;


public:
	LevelManager();
	~LevelManager();

	void Update(float time);
	void Draw(Buffer& buffer);
	
	void Event(float time);

};

