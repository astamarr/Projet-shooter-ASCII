#pragma once
#include "PlayerObject.h"
class Ennemi :
	public PlayerObject
{
private:

public:
	Ennemi();
	~Ennemi();

	void Update(float time);
};

