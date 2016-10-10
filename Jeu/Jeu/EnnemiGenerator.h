#pragma once

#include "Ennemi.h"
#include <vector>
class EnnemiGenerator
{
private:
	std::vector<Ennemi> vector;
	unsigned int nextAvailable = 0;


public:
	EnnemiGenerator();
	~EnnemiGenerator();

	void Update(float time);
	bool Collide(Objet& cible);
	void Generate(int seed);
	unsigned int AddEnnemi(const Ennemi& ennemi);
	void SearchNext();
	void Draw(Buffer& buffer);
	void Action(ProjectileVector& proj, float time);
	void Collide(ProjectileVector& proj);

	void Clear();
};

