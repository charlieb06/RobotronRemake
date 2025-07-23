#include "EnemyBullet.h"
#include <iostream>
EnemyBullet::EnemyBullet()
{

}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::MoveTowardsTarget(Vector2f target, float dt)
{

}

bool EnemyBullet::CheckIfOOB(Vector2f bounds, int offset)
{
    if (bulletShape.getPosition().x < offset)
    {
        oobLocation = "Left";
        return true;
    }
    else if (bulletShape.getPosition().x > bounds.x + offset) //right side needs extra -15 because of shape outline
    {
        oobLocation = "Right";
        return true;
    }
    else if (bulletShape.getPosition().y < offset)
    {
        oobLocation = "Up";
        return true;
    }
    else if (bulletShape.getPosition().y > bounds.y + offset)
    {
        oobLocation = "Down";
        return true;
    }
    else
    {
        oobLocation = "None";
        return false;
    }
}

bool EnemyBullet::UpdateBounce()
{
    currentBounce++;
    if (currentBounce >= maxBounce)
    {
        std::cout << "should not bounce";
        return true;
    }
    else
    {
        std::cout << "should bounce";
        InvertMomentum();
        return false;
    }
}

void EnemyBullet::InvertMomentum()
{
    if (oobLocation == "Left")
    {
        //converts negative momentum into positive
        currentVelocity.x = (currentVelocity.x -1);
    }
    else if (oobLocation == "Right")
    {
        currentVelocity.x = (currentVelocity.x * -1);
    }
    else if (oobLocation == "Up")
    {
        currentVelocity.y = (currentVelocity.y * -1);
    }
    else if (oobLocation == "Down")
    {
        currentVelocity.y = (currentVelocity.y * -1);
    }
}
