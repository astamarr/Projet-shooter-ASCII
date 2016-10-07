#pragma once
#include "PlayerObject.h"
#include "ProjectileVector.h"

#define EN_BASIC 0
#define EN_RUNNER 1
#define EN_BIGONE 2
#define EN_DELTA 3

class Ennemi :
	public PlayerObject
{
private:
	int _type;
	string LinkedRes;

public:
	Ennemi();
	Ennemi(int type, int x, int y);
	~Ennemi();

	void Set();
	void Update(float time);
	void Action(ProjectileVector& proj, float time);
	void Draw(Buffer& buffer);

};

