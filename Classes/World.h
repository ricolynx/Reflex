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

class World
{
private :
    
    //the next entity id
    int _nextEntityId = 0;
    
    //the list of entities of the workd
    std::list<Entity> entities;
    
    //add an entity to the world
    void addEntity(Entity*);
    
    
public :
    
    //constructor
    World();
    //destructor
    ~World();

    //init the world
    void init();
    
    //add a spaceship
    void addSpaceship();
    
    //get the number of entities
    int getNbEntities();
    
    //update loop of the world
    void update(float dt);
};

#endif /* defined(__Reflex__World__) */
