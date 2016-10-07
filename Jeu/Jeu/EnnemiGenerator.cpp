#include "EnnemiGenerator.h"



EnnemiGenerator::EnnemiGenerator()
{
}


EnnemiGenerator::~EnnemiGenerator()
{
}

void EnnemiGenerator::Update(float time) {
	for (auto& it : vector) {
		if (it.isAlive())
 			it.Update(time);
		if (it.GetX() < 0 || it.GetY() < 0 || it.GetX() >= Buffer::SCREEN_WIDTH || it.GetY() >= Buffer::SCREEN_HEIGHT)
			it.Kill();
	}
}

bool EnnemiGenerator::Collide(Objet& cible) {
	for (auto& it : vector)
		if (it.Collide(cible))
			return true;
	return false;
}

void EnnemiGenerator::Generate(int seed) {
	switch (seed) {
		case 0:
			AddEnnemi(Ennemi(EN_BASIC, Buffer::SCREEN_WIDTH - 1, rand() % Buffer::SCREEN_HEIGHT));
			AddEnnemi(Ennemi(EN_RUNNER, Buffer::SCREEN_WIDTH - 1, rand() % Buffer::SCREEN_HEIGHT));
			break;
		default:
			break;
	}
}

unsigned int EnnemiGenerator::AddEnnemi(const Ennemi& ennemi) {
	unsigned int position = nextAvailable;
	if (position == vector.size()) {
		vector.push_back(ennemi);
	}
	else {
		vector[position] = ennemi;
	}
	vector[position].Alive();
	SearchNext();
	return position;
}

void EnnemiGenerator::SearchNext() {
	while (nextAvailable < vector.size())
		++nextAvailable;
}

void EnnemiGenerator::Draw(Buffer& buffer) {
	for (auto& it : vector)
		if(it.isAlive())
			it.Draw(buffer);
}

void EnnemiGenerator::Action(ProjectileVector& proj, float time) {
	for (auto& it : vector)
		if(it.isAlive())
			it.Action(proj, time);
}
