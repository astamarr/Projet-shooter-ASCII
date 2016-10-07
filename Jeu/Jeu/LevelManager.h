#pragma once

#include <vector>
#include <Windows.h>
#include "Buffer.h"
#include "EnnemiGenerator.h"
#include "ProjectileVector.h"
#include "Assets.h"

class LevelManager
{
private:
	EnnemiGenerator ennemis;
	ProjectileVector playerProjectile;
	ProjectileVector ennemiProjectile;
	PlayerObject player;

	Assets &_assets;

	float levelTimer = 0;


public:
	LevelManager();
	LevelManager(Assets &assets) : _assets(assets) {};
	~LevelManager();

	void Update(float time);
	void Draw(Buffer& buffer);
	
	void Event(float time);

};
