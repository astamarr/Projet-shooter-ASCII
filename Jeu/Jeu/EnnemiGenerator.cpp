#include "EnnemiGenerator.h"



EnnemiGenerator::EnnemiGenerator()
{
}


EnnemiGenerator::~EnnemiGenerator()
{
}

void EnnemiGenerator::Update(float time) {
	for(auto& it : vector)
		it.Update(time);
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
		it.Draw(buffer);
}
