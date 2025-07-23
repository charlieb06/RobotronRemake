#pragma once
#include <SFML/Graphics.hpp>
#include "Collision.h"
#include "SoundManager.h"
#include <vector>

using namespace std;
using namespace sf;

class Bullet
{
private:
	Vector2f bulletPosition;
	float bulletMovementMultiplier;
public:
	Bullet();
	~Bullet();
	RectangleShape bulletShape;
	Vector2f currentVelocity;
	float maxSpeed;
	void BulletMovement(float dt);
	vector <Bullet> EraseBullet(vector<Bullet> bullets, int posToErase);
	bool CheckIfOOB(Vector2f bounds, int offset);

	Collision GetCollider() { return Collision(bulletShape); };
	//SoundManager& instance = SoundManager::getInstance();
};
