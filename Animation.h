#pragma once
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;

class Animation
{
public:
	Animation();
	~Animation();

	void AnimationInit(Texture* texture, Vector2u imageCount, float switchTime);

	void Update(int row, float deltaTime, bool faceRight);
	sf::IntRect uvRect;

private:
	Vector2u imageCount;
	Vector2u currentImage;

	Texture* thisTexture;

	int uvWidth;
	int uvHeight;

	float totalTime;
	float switchTime;
};
