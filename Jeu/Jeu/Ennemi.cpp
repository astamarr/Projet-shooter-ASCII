#include "Ennemi.h"



Ennemi::Ennemi()
{
}


Ennemi::~Ennemi()
{
}

void Ennemi::Update(float time) {
	Objet::Update(time);
	if (_life <= 0)
		Kill();

}
