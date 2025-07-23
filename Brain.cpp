#include "Brain.h"
#include <iostream>

Brain::Brain(float dt)
{
	this->maxSpeed = 10.f;
    this->enemyMovementOffset = dt * 15;
    this->enemyShape.setPosition(enemyShape.getGeometricCenter());
    this->enemyName = "Brain";
    this->score = 500;

    enemyTexture.loadFromFile("assets/sprites/brainSprites.png");
    enemyShape.setTexture(&enemyTexture);
    enemyShape.setTextureRect(enemyAnimation.uvRect);
    enemyPosition = enemyShape.getGeometricCenter();

    enemyAnimation.AnimationInit(&enemyTexture, Vector2u(3, 4), dt * 6);
}

Brain::~Brain()
{
}

void Brain::InitBrain(Vector2f enemyPositionPar, Vector2f bounds, vector<Family*> familiesParam, const std::shared_ptr<SoundManager> sM)
{
    enemyPosition = enemyPositionPar;
    enemyShape.setPosition(enemyPositionPar);
    families = familiesParam;
    boundsNew = bounds;
    if (familiesParam.size() != 0)
    {
        familyToTarget = familiesParam[(0 + rand() % families.size())];
        //familyToTarget = familiesParam[int(0 + rand() % familiesParam.size())];
        //targetLocation = familyToTarget->enemyShape.getPosition();
    }
    else
    {
    }
}

void Brain::MoveTowardPosition(Vector2f targetPosition, float dt)
{
    enemyMovementTimer+= dt;
    if (families.size() != 0 && familyToTarget != nullptr)
    {
        seekTargetPosition = familyToTarget->enemyShape.getPosition();
    }
    else
    {
        seekTargetPosition = targetPosition;
    }
    if (enemyMovementTimer > enemyMovementOffset)
    {
        enemyShape.setTextureRect(enemyAnimation.uvRect);
        //Brains have two AIs they will switch from. If there is a family, they will seek. if not, they will wander.
        sf::Vector2f dirToTarget = seekTargetPosition - enemyPosition;
        if (dirToTarget.length() != 0.0f)
        {
            currentVelocity = dirToTarget.normalized() * maxSpeed;
        }
        enemyPosition += currentVelocity * dt * enemyMovementMultiplier;
        enemyAnimation.Update(0, dt, true);
        enemyShape.setTextureRect(enemyAnimation.uvRect);
        enemyShape.setPosition(enemyPosition);
        enemyMovementTimer = 0;
    }
}

void Brain::UpdateFamilies(vector<Family*> familiesParam)
{
    families = familiesParam;
}

void Brain::TargetNewFamily()
{
    if (families.size() != 0)
    {
        //gets a random family from vector and sets as target. Will be called whenever family is saved/killed/turned
        familyToTarget = families[int(rand() % families.size())];
        targetLocation = familyToTarget->enemyShape.getPosition();
    }
    else
    {
        seekTargetPosition = Vector2f(50.f, 500.f);
    }
}

void Brain::CheckIfTargetDied(Family* family)
{
    if (familyToTarget == family)
    {
        //familyToTarget = families[int(rand() % families.size())];
        //targetLocation = familyToTarget->enemyShape.getPosition();
        TargetNewFamily();
        //shouldSeekPlayer = false;
    }
    else if (families.size() == 0)
    {
        shouldSeekPlayer = true;
    }

    //if (families.size() != 0)
    //{ 
    //}
    //else if (families.size() == 0)
    //{
    //    targetLocation = player.GetPlayerPositon();
    //}
}
