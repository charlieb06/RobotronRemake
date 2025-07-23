#pragma once
#include "Enemy.h"

class Hulk : public Enemy
{
protected:
	Vector2f seekTargetPosition;
	bool isTargetReached;
	Vector2f boundsNew;
public:
	Hulk(float dt);
	~Hulk();
	void MoveTowardPosition(Vector2f targetPosition, float dt) override;
	void Init(Vector2f enemyPositionPar, Vector2f window, const std::shared_ptr<SoundManager> sM) override;
};
