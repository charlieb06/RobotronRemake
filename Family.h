#pragma once
#include "Enemy.h"
class Family : public Enemy
{
private:
protected:
	Vector2f seekTargetPosition;
	bool isTargetReached;
	float familyMovementOffset = 8;
	float familyMovementTimer = 0;

public:
	Family();
	~Family();
	void MoveTowardPosition(Vector2f targetPosition, float dt) override;
	void Init(Vector2f enemyPositionPar, Vector2f bounds, const std::shared_ptr<SoundManager> sM) override;

	Texture familyTexture;
	Animation familyAnimation;
};

