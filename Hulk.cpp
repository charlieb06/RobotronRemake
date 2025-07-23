#include "Hulk.h"
#include <iostream>

Hulk::Hulk(float dt)
{
	this->maxSpeed = 1.5f * 6;
	this->enemyName = "Hulk";
	this->isImmortal = true;
	this->enemyMovementOffset = dt * 6;

	enemyTexture.loadFromFile("assets/sprites/hulkSprites.png");
	enemyShape.setTexture(&enemyTexture);
	enemyShape.setTextureRect(enemyAnimation.uvRect);
	enemyPosition = enemyShape.getGeometricCenter();

	enemyAnimation.AnimationInit(&enemyTexture, Vector2u(3, 3), dt * 1);
}

Hulk::~Hulk()
{
}

void Hulk::MoveTowardPosition(Vector2f targetPosition, float dt)
{
	enemyMovementTimer += dt;
	enemyShape.setTextureRect(enemyAnimation.uvRect);
	//checks to see if tank is within small range of target position
	if (enemyPosition.x >= seekTargetPosition.x - 10 && enemyPosition.x <= seekTargetPosition.x + 10 ||
		enemyPosition.y >= seekTargetPosition.y - 10 && enemyPosition.y <= seekTargetPosition.y + 10)
	{
		//Checks to see if tank needs new position, will generate new one
		isTargetReached = true;
	}
	//Tank uses wander Ai. Will move to a random position, then move to a different random position.
	if (isTargetReached)
	{
		//If tank has reached position, generate new position
		seekTargetPosition = Vector2f(boundsOffset + std::rand() % int(boundsNew.x), boundsOffset + std::rand() % int(boundsNew.y));
		isTargetReached = false;
	}
	if (!isTargetReached && enemyMovementTimer >= enemyMovementOffset)
	{
		//If tank hasnt reached position, move to position
		sf::Vector2f dirToTarget = seekTargetPosition - enemyPosition;
		if (dirToTarget.length() != 0.0f)
		{
			currentVelocity = dirToTarget.normalized() * maxSpeed;
		}
		if (currentVelocity.y > 0)
		{
			enemyAnimation.Update(2, dt, true);
		}
		else if (currentVelocity.x > 0)
		{
			enemyAnimation.Update(1, dt, true);
		}
		else
		{
			enemyAnimation.Update(0, dt, true);
		}

	enemyPosition += currentVelocity * dt * enemyMovementMultiplier;
	enemyShape.setPosition(enemyPosition);
	//logically this shouldnt work, timer should always be set to 0 before its > movement offset
	//this might be black magic. or im stupid
	enemyMovementTimer = 0;
	}
}

void Hulk::Init(Vector2f enemyPositionPar, Vector2f bounds, const std::shared_ptr<SoundManager> sM)
{
	soundManager = sM;
    enemyPosition = enemyPositionPar;
    enemyShape.setPosition(enemyPositionPar);
	boundsNew = bounds;
	seekTargetPosition = Vector2f(boundsOffset + std::rand() % int(boundsNew.x), boundsOffset + std::rand() % int(boundsNew.y));
}
