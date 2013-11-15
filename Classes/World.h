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


#include "cocos2d.h"
#include "Entity.h"
#include "MoveSystem.h"


class World
{
private :
    
    cocos2d::CCLayer* scene;
    
    cocos2d::CCSpriteBatchNode* batchNode;
    
    //the next entity id
    int nextEntityId = 0;
    
    //the list of entities of the workd
    Entity* canon;
    
    std::list<Entity> enemies;
    
    std::list<Entity> bullets;
    
    cocos2d::CCPoint getRandomPoint();
    
    MoveSystem *moveSys;
    
public :
    
    //constructor
    World(cocos2d::CCLayer* s);
    //destructor
    ~World();
    
    //add an enemy entity to the world
    void addEnemy();

    
    //update loop of the world
    void update(float dt);
};

#endif /* defined(__Reflex__World__) */
