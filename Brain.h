#pragma once
#include "Enemy.h"
#include "Family.h"
#include "Player.h"

class Brain : public Enemy
{
private:
	vector<Family*> families;
	Family* familyToTarget;
	Vector2f targetLocation;
	Vector2f seekTargetPosition;
	bool shouldSeekPlayer = true;
	bool isTargetReached;
	Vector2f boundsNew;
	//Player player;
	int seekFamilyIndex;
public:
	Brain(float dt);
	~Brain();
	void InitBrain(Vector2f enemyPositionPar, Vector2f bounds, vector<Family*> familiesParam, const std::shared_ptr<SoundManager> sM);
	void MoveTowardPosition(Vector2f targetPosition, float dt) override;
	void UpdateFamilies(vector<Family*> familiesParam);
	void TargetNewFamily() override;
	void CheckIfTargetDied(Family* family);
};
