#include "Animation.h"
#include <iostream>

Animation::Animation()
{
}

Animation::~Animation()
{
}

void Animation::AnimationInit(Texture* texture, Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;
	this->thisTexture = texture;
	this->uvWidth = texture->getSize().x / imageCount.x;
	this->uvHeight = texture->getSize().y / imageCount.y;
	totalTime = 0;
	currentImage.x = 0;

	sf::IntRect r1(Vector2(0, 0), Vector2i(uvWidth, uvHeight));
	uvRect = r1;
}

void Animation::Update(int row, float dt, bool isLooping)
{
	currentImage.y = row;
	totalTime += dt;

	if (totalTime >= switchTime)
	{
		//not '=' because game will never run fast enough to truly be equal
		totalTime -= switchTime;
		currentImage.x++;
		if (currentImage.x >= imageCount.x && isLooping)
		{
			currentImage.x = 0;
		}
		else if (currentImage.x >= imageCount.x && !isLooping)
		{
			currentImage.x--;
		}

		sf::IntRect r1(Vector2i(currentImage.x * uvWidth, currentImage.y * uvHeight), Vector2i(uvWidth, uvHeight));
		uvRect = r1;
	}
}
