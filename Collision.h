#pragma once
#include <SFML/Graphics.hpp>

class Collision
{
public:
	Collision(sf::RectangleShape body);
	~Collision();

	void Move(float dx, float dy) { body.move(sf::Vector2f(dx, dy)); }

	bool CheckCollision(sf::RectangleShape thisShape, sf::RectangleShape other);
	sf::Vector2f GetPosition() { return body.getPosition(); }
	sf::Vector2f GetHalfSize() { return body.getSize() / 2.0f; }

	sf::RectangleShape& body;
};
