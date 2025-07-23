#pragma once
#include "SFML/Graphics.hpp"
#include "EnforcerBullet.h"
#include "EnemyBullet.h"
#include "TankBullet.h"
#include <vector>

class EnemyBulletManager
{
public:
	EnemyBulletManager();
	~EnemyBulletManager();
	void SpawnEnemyBullet(sf::String enemyName, Vector2f targetLocation, float dt);
	vector<EnemyBullet*> ReturnEnemyBullets() { return enemyBullets; };
	vector<EnemyBullet*> DeleteEnemyBullet(int bulletToErase);
	vector<EnemyBullet*> DeleteAllBullets();
	void Init(int boundsOffsetP, Vector2f boundsP);
private:
	int boundsOffset;
	Vector2f bounds;
	Vector2f targetLocation;
	vector<EnemyBullet*> enemyBullets;
};
