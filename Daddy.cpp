#include "Daddy.h"

Daddy::Daddy(float dt)
{
	this->maxSpeed = 15.f;
	this->familyMovementOffset = dt * 8;
	this->enemyName = "Daddy";
	//Family subclasses only exist to load each spritemap seperately, rather than every family having every spritemap
	this->familyTexture.loadFromFile("assets/sprites/daddySprites.png");
	this->enemyShape.setTexture(&familyTexture);
	familyAnimation.AnimationInit(&familyTexture, Vector2u(3, 4), dt * 3);
	enemyShape.setTextureRect(familyAnimation.uvRect);
}

Daddy::~Daddy()
{
}
