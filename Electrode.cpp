#include "Electrode.h"
#include <iostream>

Electrode::Electrode(int electrodeSpriteWidth, const std::shared_ptr<SoundManager> sM)
{
	this->enemyShape.setSize(Vector2f(20.f, 20.f));
	this->score = 20;
	//this->enemyShape.setFillColor(sf::Color(0,0,0,255));
	this->enemyName = "Electrode";
	enemyTexture.loadFromFile("assets/sprites/electrodeSprites.png");
	enemyShape.setTexture(&enemyTexture);

	Vector2u textureSize = enemyTexture.getSize();
	textureSize.x = 10;
	IntRect r1 = IntRect(Vector2i(5 * 10, 0), Vector2i(textureSize.x, textureSize.y));
	enemyShape.setTextureRect(r1);
}

Electrode::~Electrode()
{
}
