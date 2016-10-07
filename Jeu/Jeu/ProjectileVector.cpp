#include "ProjectileVector.h"






ProjectileVector::~ProjectileVector()
{
}


unsigned int ProjectileVector::AddObject(const Projectile& obj) {
	unsigned int position = nextAvailable;
	if (position == vector.size()) {
		vector.push_back(obj);
	}
	else {
		vector[position] = obj;
	}
	vector[position].Alive();
	SearchNext();
	return position;
}

unsigned int ProjectileVector::AddObject(const Projectile& obj, int x, int y) {
	unsigned int position = AddObject(obj);
	vector[position].SetPosition(x, y);
	return position;
}

bool ProjectileVector::Collide(const Objet& obj) {
	for (auto& it : vector)
		if (it.isAlive() && it.Collide(obj))
			return true;
	return false;
}

void ProjectileVector::SearchNext() {
	while (nextAvailable < vector.size() && vector[nextAvailable].isAlive())
		nextAvailable++;
}

void ProjectileVector::Update(const float time) {
	for (auto& it : vector)
		if(it.isAlive())
			it.Update(time);
}

void ProjectileVector::Draw(Buffer& buffer) {
	for (auto& it : vector) {
		if(it.isAlive())
			buffer.CheckAndUpdate(it.GetY(), it.GetX(), '+', 0x0F);
	}
}

void ProjectileVector::UpdateWithBoundCheck(float time) {
	for (auto& it : vector) {
		if (it.isAlive())
			it.Update(time);
		if (it.GetX() < 0 || it.GetY() < 0 || it.GetX() >= Buffer::SCREEN_WIDTH || it.GetY() >= Buffer::SCREEN_HEIGHT)
			it.Kill();
	}
}
