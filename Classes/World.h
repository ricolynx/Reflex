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

class World
{
private :
    
    bool showLogs;
    
    cocos2d::CCLayer* scene;
    
    cocos2d::CCSpriteBatchNode* batchNode;
    
    MoveSystem *moveSys;
    
    CollisionSystem *collisionSys;
    
    //show or not collision zones
    bool showCollisionZones;
    
    //the next entity id
    int nextEntityId;
    
    //a counter 
    int count;
    
    //canon angle
    int canonAngle;
    
    bool rotateCanon;
    
    //the list of entities of the workd
    
    std::list<std::shared_ptr<Entity>> enemies;
    
    std::list<std::shared_ptr<Entity>> bullets;

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
    
    void removeDeadEnemies();
    
    //fire a single bullet
    void fireSingleBullet(std::shared_ptr<Entity> from, int angle, float speed);
    
    // fire n bullets
    void fireBullets(std::shared_ptr<Entity> from, int nbBullets, float speed);
    
public :
    
    //constructor
    World(cocos2d::CCLayer* s);
    //destructor
    ~World();
    
    //canon entity
    std::shared_ptr<Entity> canon;
    
    //add an enemy entity to the world
    void addEnemy();
    
    //update loop of the world
    void update(float dt);
    
    //when touch starts
    void onTouchesBegan(cocos2d::CCSet* touches);
    
    //when touch stops
    void onTouchesEnded(cocos2d::CCSet* touches);
};

#endif /* defined(__Reflex__World__) */
