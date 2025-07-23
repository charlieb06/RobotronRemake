#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Collision.h"#
#include "SoundManager.h"
#include <vector>

using namespace sf;
using namespace std;

class Enemy
{
public:
    RectangleShape enemyShape;
    Vector2f enemyPosition;
    Enemy();
    ~Enemy();
protected:
    Vector2f currentVelocity;
    Vector2f windowSize; //used to generate random pos on screen
    float maxSpeed;
    float enemyMovementMultiplier = 60.f; //offsets delta time
    float knockbackFrameLength = 6.f; //number of frames tank should be taking knockback
    bool isImmortal = false;
    bool isFamily = false;
    bool shouldTakeKnockback = false;
    int score;
    int boundsOffset;
    float enemyMovementOffset;
    float enemyMovementTimer = 0;
    String enemyName;
    Texture enemyTexture;
    Animation enemyAnimation;
    std::shared_ptr<SoundManager> soundManager;
public:
	virtual void MoveTowardPosition(Vector2f targetPosition, float dt);
	virtual void TakeKnockback(float dt, Vector2f bulletVelocity);
	virtual void Init(Vector2f enemyPositionPar, Vector2f window, const std::shared_ptr<SoundManager> sM);
    virtual void TargetNewFamily() {};
    virtual void UpdateSpawnedEnemies() {};
    bool ImmortalityCheck();
    Collision GetCollider() { return Collision(enemyShape); };
    int GetScore() { return score; };
    String GetName() { return enemyName; }
    void PassOffset(int bounds) { boundsOffset = bounds; }
};