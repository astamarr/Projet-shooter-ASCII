#include "LevelManager.h"




LevelManager::~LevelManager()
{
}

void LevelManager::Reset() {
	player.Alive();
	player.SetLife(3);
	player.SetMaxSpeed(50.f);
	player.SetMaxAcc(5.f);
	player.SetMaxDec(5.f);
	_levelBackground = BG_STARS;
	_levelSpeed = 100.f;
}

void LevelManager::Refresh(Buffer &buffer, float time) {
	Draw(buffer);
	UpdateBackground(buffer, time);
	Update(time);
	if(_levelState!=LVL_LOST) Event(time);
	UpdateLevel(buffer, time);
}

void LevelManager::Update(float time) {
	ennemis.Update(time);
	ennemis.Action(ennemiProjectile, time);
	playerProjectile.UpdateWithBoundCheck(time);
	ennemiProjectile.UpdateWithBoundCheck(time);
	player.Update(time);
	ennemis.Collide(playerProjectile);
	ennemiProjectile.Collide(player);
	levelTimer += time;
	enemyTimer += time;
	_boostTimer += time;
	if (!player.isAlive())
		_levelState = LVL_LOST;
	
}

void LevelManager::UpdateLevel(Buffer &buffer, float time) {
	switch (_levelState) {
	case LVL_START:
		if ((int)(levelTimer*2) % 2 == 0)
			buffer.DrawText("START!", 50, 20, 0x02);
		if (levelTimer > 5.f) {
			_levelState=LVL_GOING;
			enemyTimer = 0.f;
			levelTimer = 0.f;
		}
		break;
	case LVL_GOING:
		if (enemyTimer>1.f) {
			ennemis.Generate(0);
			enemyTimer = 0.f;
		}
		if (levelTimer > 30.f) {
			_levelBackground = BG_WARP;
			levelTimer = 0.f;
			_levelState = LVL_WARPING;
		}
		break;
	case LVL_WARPING:
		_levelBackground = BG_WARP;
		if (levelTimer < 10.f && _levelSpeed < 1000.f)
			_levelSpeed += time * 200;
		if (levelTimer > 10.f && _levelSpeed >100.f) {
			_levelSpeed -= time * 200;
		}
		if (levelTimer > 10.f && _levelSpeed < 100.f) {
			_levelSpeed = 100.f;
			_levelState = LVL_START;
			_levelBackground = BG_STARS;
			levelTimer = 0.f;
		}
		break;
	case LVL_LOST:
		//buffer.DrawText("Perdu!", 10, 5, 0x0F);
		buffer.UpdateFromAsset(15, 50, "gameover");
		break;
	default:
		break;
	}
}

void LevelManager::UpdateBackground(Buffer &buffer, float time) {
	switch (_levelBackground) {
	case BG_STARS:
	case BG_WARP:
		buffer.MoveStars(-_levelSpeed, 0, time);
		break;
	default:
		break;
	}
}

void LevelManager::Draw(Buffer& buffer) {
	DrawBackground(buffer);
	ennemis.Draw(buffer);
	playerProjectile.Draw(buffer);
	ennemiProjectile.Draw(buffer);
	if(player.isAlive()) player.Draw(buffer);
	DrawInterface(buffer);
}

void LevelManager::DrawBackground(Buffer &buffer) {
	switch (_levelBackground) {
	case BG_STARS:
		buffer.DrawStars();
		break;
	case BG_WARP:
		buffer.DrawWarp(_levelSpeed);
		break;
	default:
		break;
	}
}

void LevelManager::DrawInterface(Buffer &buffer) {
	buffer.DrawText(player.GetWeaponName(), 20, 0, 0x04);
}

void LevelManager::Event(float time) {
	if (GetAsyncKeyState('Q'))
		player.Move(-1,0,time);
	if (GetAsyncKeyState('D'))
		player.Move(1,0,time);
	if (GetAsyncKeyState('S'))
		player.Move(0,1,time);
	if (GetAsyncKeyState('Z'))
		player.Move(0,-1,time);
	if (GetAsyncKeyState(VK_SHIFT))
		player.RollWeapon();
	if (GetAsyncKeyState(VK_SPACE)) 
		player.Shoot(playerProjectile);

	if (GetAsyncKeyState(VK_DOWN) && _boostTimer > 5.f) {
		player.SetYSpeed(100.f);
		_boostTimer = 0;
	}
	if (GetAsyncKeyState(VK_UP)) {
		player.SetYSpeed(-100.f);
		_boostTimer = 0;
	}
}


