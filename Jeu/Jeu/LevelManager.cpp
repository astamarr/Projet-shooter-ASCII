#include "LevelManager.h"




LevelManager::~LevelManager()
{
}

void LevelManager::Update(float time) {
	ennemis.Update(time);
	ennemis.Action(ennemiProjectile, time);
	playerProjectile.UpdateWithBoundCheck(time);
	ennemiProjectile.UpdateWithBoundCheck(time);
	player.Update(time);
	levelTimer += time;
	if (levelTimer > 1.f) {
		ennemis.Generate(0);
		levelTimer = 0.f;
	}
}

void LevelManager::Draw(Buffer& buffer) {
	ennemis.Draw(buffer);
	playerProjectile.Draw(buffer);
	ennemiProjectile.Draw(buffer);
	player.Draw(buffer);
	
}

void LevelManager::Event(float time) {
	if (GetAsyncKeyState('Q'))
		player.Move(-1, 0, time);
	if (GetAsyncKeyState('D'))
		player.Move(1, 0, time);
	if (GetAsyncKeyState('S'))
		player.Move(0, 1, time);
	if (GetAsyncKeyState('Z'))
		player.Move(0, -1, time);
	if (GetAsyncKeyState(VK_SPACE)) {
		player.Shoot(playerProjectile);
	}
}


