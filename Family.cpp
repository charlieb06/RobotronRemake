#include "Family.h"
#include <iostream>

Family::Family()
{
    this->enemyShape.setOutlineColor(Color::Black);
    this->maxSpeed = 2;
    this->isFamily = true;
}

Family::~Family()
{
}

void Family::MoveTowardPosition(Vector2f targetPosition, float dt)
{
    familyMovementTimer += dt;
    //seek ai, same as tank
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
        seekTargetPosition = Vector2f(boundsOffset + rand() % int(windowSize.x), boundsOffset + rand() % int(windowSize.y));
        isTargetReached = false;
    }
    if (!isTargetReached && familyMovementTimer >= familyMovementOffset)
    {
        //If tank hasnt reached position, move to position
        sf::Vector2f dirToTarget = seekTargetPosition - enemyPosition;
        if (dirToTarget.length() != 0.0f)
        {
            currentVelocity = dirToTarget.normalized() * maxSpeed;
            familyMovementTimer = 0;

        }
        enemyPosition += currentVelocity * dt * enemyMovementMultiplier;
        enemyShape.setPosition(enemyPosition);
        if (currentVelocity.y > 0)
        {
            familyAnimation.Update(2, dt, true);
        }
        else if (currentVelocity.x > 0)
        {
            familyAnimation.Update(1, dt, true);
        }
        else
        {
            familyAnimation.Update(0, dt, true);
        }

    }
    enemyShape.setTextureRect(familyAnimation.uvRect);

}

void Family::Init(Vector2f enemyPositionPar, Vector2f bounds, const std::shared_ptr<SoundManager> sM)
{
    soundManager = sM;
    enemyPosition = enemyPositionPar;
    enemyShape.setPosition(enemyPositionPar);
    windowSize = bounds;
    seekTargetPosition = Vector2f(boundsOffset + rand() % int(windowSize.x), boundsOffset + rand() % int(windowSize.y));
}
