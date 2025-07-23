#pragma once
#include "SFML/Graphics.hpp"
#include "Animation.h"
#include "SoundManager.h"
#include "Enemy.h"
#include "Collision.h"

class EnemyBullet
{
public:
	EnemyBullet();
	~EnemyBullet();

	virtual void MoveTowardsTarget(Vector2f target, float dt);
	bool CheckIfOOB(Vector2f bounds, int offset);
	Collision GetCollider() { return Collision(bulletShape); };
	sf::RectangleShape bulletShape;
	string bulletName;
	string getBulletName() { return bulletName; };
	string getOOBLocation() { return oobLocation; };
	bool UpdateBounce();
	void InvertMomentum();
protected:
	int offset;
	int maxBounce = 0;
	int currentBounce = 0;
	Vector2f bounds;
	Vector2f bulletPosition;
	string oobLocation = "None";
	Vector2f currentVelocity;
	Texture bulletTexture;
	Animation bulletAnimation;
};
