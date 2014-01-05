//
//  World.h
//  Reflex
//
//  Created by Eric Giraud on 06/11/2013.
//
//

#ifndef __Reflex__World__
#define __Reflex__World__

#include <list>
#include <iostream>
#include <random>
#include <math.h>
#include <memory>


#include "cocos2d.h"

#include "Entity.h"

#include "MoveSystem.h"
#include "CollisionSystem.h"

#include "Component.h"
#include "VelocityComponent.h"
#include "TargetComponent.h"
#include "LifeComponent.h"
#include "AmmoComponent.h"
#include "BonusComponent.h"
#include "ShieldComponent.h"
#include "ParticleComponent.h"
#include "ShotGroupComponent.h"

#include "Delegate.h"
#include "SimpleDelegate.h"

class PopupLayer;
class World : public cocos2d::CCObject
{
private :
    
    bool showLogs;
    
    cocos2d::CCLayer* scene;
        
    cocos2d::CCSpriteBatchNode* batchNode;
    
    cocos2d::CCParticleBatchNode *particleBatchNode;
    
    MoveSystem *moveSys;
    
    CollisionSystem *collisionSys;
    
    //show or not collision zones
    bool showCollisionZones;
    
    bool pause;
    
    //the next entity id
    int nextEntityId;
    
    //a counter 
    int count;
    
    //count the number of shots (this is used to identify salves) and it is modulo 100
    int shotCounter;
    
    //nb enemy spawned
    int enemyCount;
    
    //canon angle
    int canonAngle;
    
    //rotation of the canon
    int rotateCanon;
    
    //get the number of lives
    int life;
    
    //the lists of entities of the workd
    
    std::list<std::shared_ptr<Entity>> enemies;
    
    std::list<std::shared_ptr<Entity>> bullets;
    
    std::list<std::shared_ptr<Entity>> bonuses;

    //get a random point
    cocos2d::CCPoint getRandomPoint();
    
    //set the initial velocity of the entity
    void setInitialVelocity(std::shared_ptr<Entity> entity, int coef);
    
    //set the initial velocity of a bullet
    void setInitialBulletVelocity(std::shared_ptr<Entity> bullet, float angle, float speed);
    
    //random engine
    std::default_random_engine randomEngine;
    
    //removeDeadBullets
    void removeDeadBullets();
    
    //remove DeadEnemies
    void removeDeadEnemies();
    
    //remove DeadBonuses
    void removeDeadBonuses();
    
    //clean the world of all bullets
    void cleanBullets();
    
    //clean the world of all enemies
    void cleanEnemies();
    
    //clean the world of all bonuses
    void cleanBonuses();
    
    //void removeDeadEntities(std::list<std::shared_ptr<Entity>> entities);
    
    //fire a single bullet
    void fireSingleBullet(std::shared_ptr<Entity> from, int angle, float speed);
    
    // fire n bullets
    void fireBullets(std::shared_ptr<Entity> from, int nbBullets, float speed);
    
    //when game over
    void gameOver();
    
    //add a shield to canon
    void addShield();
    
    //callback called at the end of a shield animation
    void onEndShieldCallback(cocos2d::CCObject *pSender);
    
    
public :
    
    //constructor
    World(cocos2d::CCLayer* s);
    //destructor
    ~World();
    
    //the worl size
    cocos2d::CCSize worldSize;
    
    //canon entity
    std::shared_ptr<Entity> canon;
    
    //add an enemy entity to the world
    void addEnemy();
    
    //add a bonus from an entity (when it's destroyed)
    void addBonusFromEntity(component::BonusComponent::BONUS_TYPE bonusType, std::shared_ptr<Entity> fromEntity);

    //update loop of the world
    void update(float dt);
    
    //when touch starts
    void onTouchesBegan(cocos2d::CCSet* touches);
    
    //when touch stops
    void onTouchesEnded(cocos2d::CCSet* touches);
    
    //get the number of remaining lives
    int getLives();
    
    //pause/unpause the game
    void pauseGame();
    
    //check if the game is paused
    bool isPaused();
    
    //reset the game
    void resetGame();
    
    //show an explosion
    void showExplosion(std::shared_ptr<Entity>  entity);
};

#endif /* defined(__Reflex__World__) */
