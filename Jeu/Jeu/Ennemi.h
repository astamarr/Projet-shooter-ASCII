#pragma once
#include "PlayerObject.h"
#include "ProjectileVector.h"

#define EN_BASIC 0

class Ennemi :
	public PlayerObject
{
private:
	int _type;

public:
	Ennemi();
	Ennemi(int type, int x, int y);
	~Ennemi();

	void Set();
	void Update(float time);
	void Action(ProjectileVector& proj, float time);

};

