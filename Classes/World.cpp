//
//  World.cpp
//  Reflex
//
//  Created by Eric Giraud on 06/11/2013.
//
//

#include "World.h"


World::World()
{
    std::cout<< "World constructor"<<std::endl;
}

World::~World()
{
    std::cout<< "World destructor"<<std::endl;
    this->entities.clear();
}


bool World::addSpaceship()
{
    Entity *spaceship = new Entity(0, Entity::spaceship);
    this->entities.push_back(*spaceship);
    
    spaceship = new Entity(1, Entity::spaceship);
    this->entities.push_back(*spaceship);
    
    return true;
}

bool World::addEntity(Entity* entity)
{
    return true;
}