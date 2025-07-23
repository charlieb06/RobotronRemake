#include "Collision.h"
#include <iostream>

using namespace std;

Collision::Collision(sf::RectangleShape body) :
	body(body)
{
}

Collision::~Collision()
{
}

bool Collision::CheckCollision(sf::RectangleShape thisShape, sf::RectangleShape other)
{
	//AABB
	//Use is simple, just pass in two shapes you want to check a collision with.
	sf::Vector2f otherPosition = other.getPosition();
	sf::Vector2f otherHalfSize = sf::Vector2f(other.getSize().x / 2, other.getSize().y / 2);
	sf::Vector2f thisPosition = thisShape.getPosition();
	sf::Vector2f thisHalfSize = sf::Vector2f(thisShape.getSize().x / 2, thisShape.getSize().y / 2);

	//cout << "Other Position X: " << otherPosition.x << endl;
	//cout << "Other Position Y: " << otherPosition.y << endl;
	//cout << "This Position X: " << thisPosition.x << endl;
	//cout << "This Position Y: " << thisPosition.y << endl;

	float deltaX = otherPosition.x - thisPosition.x;
	float deltaY = otherPosition.y - thisPosition.y;

	float intersectX = abs(deltaX) - (otherHalfSize.x + thisHalfSize.x);
	float intersectY = abs(deltaY) - (otherHalfSize.y + thisHalfSize.y);

	//cout << "Delta X: " << deltaX << endl;
	//cout << "Delta Y: " << deltaY << endl;
	//cout << "Intersect X: " << intersectX << endl;
	//cout << "Intersect Y: " << intersectY << endl;

	if (intersectX > 1.0f || intersectY > 1.0f)
	{
		return true;
	}
	else 
	{
		return false;
	}
}
