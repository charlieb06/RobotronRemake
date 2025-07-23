#include "EnforcerBullet.h"

EnforcerBullet::EnforcerBullet(Vector2f thisPosition, int offsetP, Vector2f boundsP, float dt)
{
    this->bounds = boundsP;
    this->offset = offsetP;
    this->bulletShape.setSize(Vector2f(20.f, 20.f));
    this->bulletShape.setFillColor(Color::White);
    this -> bulletPosition = thisPosition;
    this->bulletShape.setPosition(Vector2f(thisPosition));
    this->targetLocation = Vector2f(0, 0);
    this->currentVelocity = Vector2f(0, 0);
    this->bulletName = "Enforcer";

    bulletTexture.loadFromFile("assets/sprites/enforcerBulletSprite.png");
    bulletShape.setTexture(&bulletTexture);
    bulletAnimation.AnimationInit(&bulletTexture, Vector2u(4, 1), dt * 4);
    //this->dirToTarget = targetPosition - bulletShape.getGeometricCenter();
}

EnforcerBullet::~EnforcerBullet()
{
}

void EnforcerBullet::MoveTowardsTarget(Vector2f target, float dt)
{
    bulletShape.setTextureRect(bulletAnimation.uvRect);
    bulletAnimation.Update(0,dt, true);
    if (targetLocation == Vector2f(0, 0))
    {
        //target location should only be updated once, so bullet doesnt home
        targetLocation = target;
        dirToTarget = targetLocation - bulletPosition;
        if (dirToTarget.length() != 0.0f)
        {
            currentVelocity = (dirToTarget.normalized() * 3.f);
        }
    }
    bulletPosition += currentVelocity * dt * 100.f;
    bulletShape.setPosition(bulletPosition);
}
