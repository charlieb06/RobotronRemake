#pragma once
#include "Enemy.h"

class Electrode : public Enemy
{
public:
	Electrode(int electrodeSpriteWidth, const std::shared_ptr<SoundManager> sM);
	~Electrode();
};
