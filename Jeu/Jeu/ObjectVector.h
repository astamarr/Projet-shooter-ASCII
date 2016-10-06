#pragma once

#include "Objet.h"
#include <vector>
#include "Buffer.h"

class ObjectVector
{
private:
	std::vector<Objet> vector;
	unsigned int nextAvailable = 0;
public:
	ObjectVector(int size = 0) : vector(size) {};
	~ObjectVector();

	unsigned int AddObject(const Objet& obj);
	unsigned int AddObject(const Objet& obj, int x, int y);
	bool Collide(const Objet& obj);
	void SearchNext();
	void Update(const float time);
	size_t size() { return vector.size(); };
	Objet& operator[](unsigned int index) { return vector[index]; };
	void Draw(Buffer& buffer);
	void UpdateWithBoundCheck(float time);
};

