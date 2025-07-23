#include "Enforcer.h"
#include "iostream";

Enforcer::Enforcer(float dt, int bounds, Vector2f boundsSizeParam, Vector2f playerPosition, EnemyBulletManager* eBM)
{
    enemyBulletManager = eBM;
    boundsSize = boundsSizeParam;
    boundsOffset = bounds;
    //cout << "i spawned" << endl;
    this->maxSpeed = 500.f * dt;
    this->enemyMovementOffset = 3.f * dt;
    this->enemyName = "Enforcer";
    this->fireTime = 50 * dt;
    this->score = 100;

    enemyTexture.loadFromFile("assets/sprites/enforcerSprites.png");
    enemyShape.setTexture(&enemyTexture);
    enemyShape.setTextureRect(enemyAnimation.uvRect);
    enemyAnimation.AnimationInit(&enemyTexture, Vector2u(6, 1), dt * 25);
}

Enforcer::~Enforcer()
{
}

void Enforcer::MoveTowardPosition(Vector2f targetPosition, float dt)
{
    //enforcer currently is functional, will seek to player and move away if too close
    //bug where enforcer will jitter between moving to and away from the player
    enemyShape.setTextureRect(enemyAnimation.uvRect);
    enemyAnimation.Update(0, dt, false);
    if (initialWaitTimer < initialWaitTime)
    {
        enemyAnimation.Update(0, dt, false);
        enemyShape.setTextureRect(enemyAnimation.uvRect);
        initialWaitTimer += dt;
    }
    else
    {
        enemyMovementTimer += dt;
        if (enemyMovementTimer > enemyMovementOffset)
        {
            enemyAnimation.Update(0, dt, false);
            sf::Vector2f dirToTarget = targetPosition - enemyPosition;
            if (dirToTarget.length() != 0.0f)
            {
                currentVelocity = (dirToTarget.normalized() * maxSpeed);
            }

            enemyMovementTimer = 0;
            //Creates a radius around player that enforcer cannot enter
            if (enemyPosition.x <= targetPosition.x - boundsOffset * 2.5 || enemyPosition.x >= targetPosition.x + boundsOffset * 2.5 ||
                enemyPosition.y <= targetPosition.y - boundsOffset * 2.5 || enemyPosition.y >= targetPosition.y + boundsOffset * 2.5)
            {
            }
            else
            {
                currentVelocity -= Vector2f(currentVelocity.x * 2, currentVelocity.y * 2);
            }

            if (enemyPosition.x < boundsOffset + 18)
            {
                enemyPosition = Vector2f(boundsOffset + 18, enemyPosition.y);
                enemyShape.setPosition(enemyPosition);
            }
            if (enemyPosition.x > boundsSize.x + boundsOffset - 18) //right side needs extra -15 because of shape outline
            {
                enemyPosition = Vector2f(boundsSize.x + boundsOffset - 18, enemyPosition.y);
                enemyShape.setPosition(boundsSize);
            }
            if (enemyPosition.y < boundsOffset + 18)
            {
                enemyPosition = Vector2f(enemyPosition.x, boundsOffset + 18);
                enemyShape.setPosition(enemyPosition);
            }
            if (enemyPosition.y > boundsOffset + boundsSize.y - 40)
            {
                enemyPosition = Vector2f(enemyPosition.x, boundsOffset + boundsSize.y - 40);
                enemyShape.setPosition(enemyPosition);
            }
            enemyPosition += currentVelocity * dt * enemyMovementMultiplier;
            enemyShape.setPosition(enemyPosition);
            enemyMovementTimer = 0;

            fireTimer += dt;
            if (fireTimer >= fireTime)
            {
                soundManager->PlaySound(3);
                //EnforcerBullet* eB = new EnforcerBullet(targetPosition, boundsOffset, boundsSize);
                enemyBulletManager->SpawnEnemyBullet("Enforcer", enemyPosition, dt);
                fireTimer = 0;
            }
        }
    }
}

