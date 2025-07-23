#include "Enemy.h"
#include <iostream>

Enemy::Enemy()
{
    this->enemyShape.setSize(Vector2(40.f, 40.f));
    this->enemyShape.setOrigin(enemyShape.getSize() / 2.f);
    this->score = 50;
}

Enemy::~Enemy()
{
}

void Enemy::MoveTowardPosition(Vector2f targetPosition, float dt)
{
}

void Enemy::TakeKnockback(float dt, Vector2f bulletVelocity)
{
    shouldTakeKnockback = true;
    float knockbackTimer = 0;
    if (isImmortal)
    {
        enemyPosition += Vector2f(bulletVelocity.x, bulletVelocity.y);
        knockbackTimer = 0;
    }
}

void Enemy::Init(Vector2f enemyPositionPar, Vector2f bounds, const std::shared_ptr<SoundManager> sM)
{
    soundManager = sM;
    enemyShape.setPosition(enemyPositionPar);
    enemyPosition = enemyPositionPar;
    windowSize = bounds;
}



bool Enemy::ImmortalityCheck()
{
	return isImmortal;
}
