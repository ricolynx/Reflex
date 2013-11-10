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

int World::getNbEntities()
{
    return this->entities.size();
}

void World::addEntity(Entity* entity)
{
    this->_nextEntityId ++;
    this->entities.push_back(*entity);
}

void World::addSpaceship()
{
    Entity *spaceship = new Entity(this->_nextEntityId, Entity::spaceship);
    this->addEntity(spaceship);
}

void World::update(float dt)
{
    
}
