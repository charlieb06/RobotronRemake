#include "Bullet.h"

Bullet::Bullet()
{
	this->bulletShape.setSize(Vector2f(4.f, 50.f));
    this->bulletShape.setFillColor(Color::Red);
	//this->bulletShape.setRotation(degrees(90));
	this->maxSpeed = 30.f;
	this->bulletMovementMultiplier = 60.f;
}

Bullet::~Bullet()
{
}

void Bullet::BulletMovement(float dt)
{
	bulletShape.move(currentVelocity * dt * bulletMovementMultiplier);
}

vector<Bullet> Bullet::EraseBullet(vector<Bullet> bullets, int posToErase)
{
	bullets.erase(bullets.begin() + posToErase);
    return bullets;
}

bool Bullet::CheckIfOOB(Vector2f bounds, int offset)
{
    if (bulletShape.getPosition().x < offset)
    {
        return true;
    }
    else if (bulletShape.getPosition().x > bounds.x + offset) //right side needs extra -15 because of shape outline
    {
        return true;
    }
    else if (bulletShape.getPosition().y < offset)
    {
        return true;
    }
    else if (bulletShape.getPosition().y > bounds.y + offset)
    {
        return true;
    }
    else
    {
        return false;
    }
}
