#pragma once

#include "Projectile.h"
#include <vector>
#include "Buffer.h"


class ProjectileVector
{
private:
	std::vector<Projectile> vector;
	unsigned int nextAvailable = 0;
public:
	ProjectileVector(int size = 0) : vector(size) {};
	~ProjectileVector();

	unsigned int AddObject(const Projectile& obj);
	unsigned int AddObject(const Projectile& obj, int x, int y);
	bool Collide(const Objet& obj);
	void SearchNext();
	void Update(const float time);
	size_t size() { return vector.size(); };
	Objet& operator[](unsigned int index) { return vector[index]; };
	void Draw(Buffer& buffer);
	void UpdateWithBoundCheck(float time);
};

