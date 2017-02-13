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
	_levelState = LVL_START;
	levelTimer = 0.f;

	_end = false;
}

bool LevelManager::Refresh(Buffer &buffer, float time) {
	Draw(buffer);
	UpdateBackground(buffer, time);
	Update(time);
	if(_levelState!=LVL_LOST) Event(time);
	else MenuEvent(time);
	UpdateLevel(buffer, time);
	return _end;
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
	_menuTimer += time;
	if (!player.isAlive()) {
		_levelState = LVL_LOST;
	}
	
}

void LevelManager::UpdateLevel(Buffer &buffer, float time) {
	switch (_levelState) {
	case LVL_START:
		if ((int)(levelTimer*2) % 2 == 0)
			buffer.DrawText("SECTOR" + to_string(CurrentSector) + ".... FIGHT", 50, 20, 0x02);
	
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
		if (levelTimer > 20.f) {
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
			++CurrentSector;
			_levelBackground = BG_STARS;
			levelTimer = 0.f;
		}
		break;
	case LVL_LOST:
		//buffer.DrawText("Perdu!", 10, 5, 0x0F);
		buffer.UpdateFromAsset(15, 50, "gameover");
		buffer.DrawText(to_string(CurrentSector - 1) + "SECTOR CLEANED", 60, 20, 0x02);
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
	if (_levelState == LVL_LOST) {
		buffer.UpdateFromAsset(15, 50, "gameover");
		if(_menuCursor == 0)
			buffer.DrawText("Retry", 47, 20, 0x0F);
		else
			buffer.DrawText("Retry", 47, 20, 0x04);
		if(_menuCursor == 1)
			buffer.DrawText("Quit", 48, 22, 0x0F);
		else
			buffer.DrawText("Quit", 48, 22, 0x04);
	}
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
	GetAsyncKeyState(VK_RETURN);
}

void LevelManager::MenuEvent(float time) {
	if (_menuTimer < 0.5f)
		return;
	if (GetAsyncKeyState('Z')) {
		--_menuCursor;
		if (_menuCursor < 0)
			_menuCursor = _menuNumber - 1;
		_menuTimer = 0.f;
	}
	if (GetAsyncKeyState('S')) {
		++_menuCursor;
		_menuCursor %= _menuNumber;
		_menuTimer = 0.f;
	}
	if (GetAsyncKeyState(VK_RETURN)) {
		if (_menuCursor == 0)
			Reset();
		else
			_end = true;
	}
}

