#pragma once
#include "EnemyBullet.h"
#include "Animation.h"
#include <iostream>
class EnforcerBullet : public EnemyBullet
{
public:
	EnforcerBullet(Vector2f targetPosition, int offsetP, Vector2f boundsP, float dt);
	~EnforcerBullet();
	void MoveTowardsTarget(Vector2f, float dt) override;
private:
	Vector2f dirToTarget;
	Vector2f targetLocation;
};