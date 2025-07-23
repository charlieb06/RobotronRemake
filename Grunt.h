#pragma once
#include "Enemy.h"
#include "SFML/Audio.hpp"

class Grunt : public Enemy
{
public:
	Grunt(float dt);
	~Grunt();

	void MoveTowardPosition(Vector2f targetPosition, float dt) override;
	//grunts should only move once every x frames
private:
};
