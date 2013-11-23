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
    
    cocos2d::CCLayer* scene;
    
    cocos2d::CCSpriteBatchNode* batchNode;
    
    MoveSystem *moveSys;
    
    CollisionSystem *collisionSys;
    
    //the next entity id
    int nextEntityId;
    
    //a counter 
    int count;
    
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
    

    
public :
    
    //constructor
    World(cocos2d::CCLayer* s);
    //destructor
    ~World();
    
    //canon entity
    std::shared_ptr<Entity> canon;
    
    //add an enemy entity to the world
    void addEnemy();

    //fire a single bullet
    void fireSingleBullet(std::shared_ptr<Entity> from, int angle, float speed);
    
    //update loop of the world
    void update(float dt);
};

#endif /* defined(__Reflex__World__) */
