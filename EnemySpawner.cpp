//#include "EnemySpawner.h"
//
//EnemySpawner::EnemySpawner()
//{
//}
//
//EnemySpawner::~EnemySpawner()
//{
//}
//
//void EnemySpawner::MoveTowardPosition(Vector2f targetPosition, float dt)
//{
//	enemyShape.setTextureRect(enemyAnimation.uvRect);
//	enemyAnimation.Update(0, dt, false);
//
//    sf::Vector2f dirToTarget = targetPosition - enemyPosition;
//    if (dirToTarget.length() != 0.0f)
//    {
//        currentVelocity = (dirToTarget.normalized() * maxSpeed);
//    }
//
//    if (enemyPosition.x >= targetPosition.x - boundsOffset * 2 || enemyPosition.x <= targetPosition.x + boundsOffset * 2 ||
//        enemyPosition.y >= targetPosition.y - boundsOffset * 2 || enemyPosition.y <= targetPosition.y + boundsOffset * 2)
//    {
//        currentVelocity = Vector2f(currentVelocity.x * 2, currentVelocity.y * 2);
//    }
//    else
//    {
//        currentVelocity -= Vector2f(currentVelocity.x * 2, currentVelocity.y * 2);
//    }
//}