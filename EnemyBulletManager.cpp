#include "EnemyBulletManager.h"
#include <iostream>

EnemyBulletManager::EnemyBulletManager()
{
}

EnemyBulletManager::~EnemyBulletManager()
{
}

void EnemyBulletManager::SpawnEnemyBullet(sf::String enemyName, Vector2f targetLocation, float dt)
{
	if (enemyName == "Enforcer")
	{
		EnforcerBullet* eB = new EnforcerBullet(targetLocation, boundsOffset, bounds, dt);
		enemyBullets.push_back(eB);
	}
	else if (enemyName == "Tank")
	{
		TankBullet *eB = new TankBullet(targetLocation, boundsOffset, bounds);
		enemyBullets.push_back(eB);
	}
	//add fired bullet to vector
	ReturnEnemyBullets(/*pass in bullet vector*/);
}

vector<EnemyBullet*> EnemyBulletManager::DeleteAllBullets()
{
	enemyBullets.clear();
	return enemyBullets;
}

void EnemyBulletManager::Init(int boundsOffsetP, Vector2f boundsP)
{
	boundsOffset = boundsOffsetP;
	bounds = boundsP;
}

vector<EnemyBullet*> EnemyBulletManager::DeleteEnemyBullet(int bulletToErase)
{
	enemyBullets.erase(enemyBullets.begin() + bulletToErase);
	return vector<EnemyBullet*>();
}
