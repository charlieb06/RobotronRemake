#include "Grunt.h"

Grunt::Grunt(float dt)
{
    this->maxSpeed = 30.f;
    this->enemyMovementOffset = dt * 15;
    this->enemyName = "Grunt";
    this->score = 200;

    enemyTexture.loadFromFile("assets/sprites/gruntSprites.png");
    enemyShape.setTexture(&enemyTexture);
    enemyShape.setTextureRect(enemyAnimation.uvRect);

    //can cause animation of first enemy in first wave to bug out
    enemyAnimation.AnimationInit(&enemyTexture, Vector2u(3, 1), dt * 25);

}

Grunt::~Grunt()
{
}

void Grunt::MoveTowardPosition(Vector2f targetPosition, float dt)
{
    enemyShape.setTextureRect(enemyAnimation.uvRect);
    enemyAnimation.Update(0, dt, true);
    enemyMovementTimer += dt;
    if (enemyMovementTimer >= enemyMovementOffset)
    {
	    sf::Vector2f dirToTarget = targetPosition - enemyPosition;
        if (dirToTarget.length() != 0.0f)
        {
            currentVelocity = (dirToTarget.normalized() * maxSpeed);
        }

        soundManager->PlaySound(6);
        enemyPosition += currentVelocity * dt * enemyMovementMultiplier;
        enemyShape.setPosition(enemyPosition);
        enemyMovementTimer = 0;
    }
}
