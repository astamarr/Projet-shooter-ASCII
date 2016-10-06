#include "ObjectVector.h"



/*ObjectVector::ObjectVector()
{
}*/


ObjectVector::~ObjectVector()
{
}

unsigned int ObjectVector::AddObject(const Objet& obj) {
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

unsigned int ObjectVector::AddObject(const Objet& obj, int x, int y) {
	unsigned int position = AddObject(obj);
	vector[position].SetPosition(x, y);
	return position;
}

bool ObjectVector::Collide(const Objet& obj) {
	for (auto& it : vector)
		if (it.Collide(obj))
			return true;
	return false;
}
void ObjectVector::SearchNext() {
	while (nextAvailable < vector.size() && vector[nextAvailable].isAlive())
		nextAvailable++;
}

void ObjectVector::Update(const float time) {
	for (auto& it : vector)
		it.Update(time);
}

void ObjectVector::Draw(Buffer& buffer) {
	for (auto& it : vector) {
		if(it.isAlive())
			buffer.Update(it.GetY(), it.GetX(), '+', 0x0F);
	}
}