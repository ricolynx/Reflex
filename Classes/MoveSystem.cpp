//
//  MoveSystem.cpp
//  Reflex
//
//  Created by Eric Giraud on 13/11/2013.
//
//

#include "MoveSystem.h"

MoveSystem::MoveSystem()
{
    std::cout << "MoveSystem - constructor - " << std::endl;
}


MoveSystem::~MoveSystem()
{
    std::cout << "MoveSystem - destructor - " << std::endl;
    this->movingEntities.clear();
}


void MoveSystem::addEntity(Entity *entity)
{
    this->movingEntities.push_back(*entity);
}

void MoveSystem::removeEntity(Entity* entity)
{
    this->movingEntities.remove(*entity);
}

void MoveSystem::move(std::list<Entity>::iterator *entity)
{
    
}


void MoveSystem::update(float dt)
{
    for (std::list<Entity>::iterator it = this->movingEntities.begin();it != this->movingEntities.end(); it++)
    {
        this->move(&it);
    }
}

