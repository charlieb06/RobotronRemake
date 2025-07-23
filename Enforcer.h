#pragma once
#include "Enemy.h"
#include "Player.h"
#include "EnforcerBullet.h"
#include "EnemyBulletManager.h"

class Enforcer : public Enemy
{
public:
	Enforcer(float dt, int bounds,Vector2f boundsSize, Vector2f playerPosition, EnemyBulletManager* eBM);
	~Enforcer();

	void MoveTowardPosition(Vector2f targetPosition, float dt) override;
	void GetPlayerVelocity(Vector2f playerVelocityParam) { playerVelocity = playerVelocityParam; };
private:
	Vector2f screenSizeOffset;
	Player* playerPtr;
	Vector2f playerVelocity;
	Vector2f boundsSize;
	EnemyBulletManager* enemyBulletManager;
	float fireTime = 1.f;
	float fireTimer = 0;

	float initialWaitTimer = 0;
	float initialWaitTime = 1.5;
	//grunts should only move once every x frames
};
