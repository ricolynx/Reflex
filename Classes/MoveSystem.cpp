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
}


void MoveSystem::addEntity(Entity* entity)
{
    this->movingEntities.push_back(*entity);
}

void MoveSystem::removeEntity(int entityId)
{
    /*std::list<Entity>::iterator it;
    int i = 0;
    for (it = this->movingEntities.begin(); it!= this->movingEntities.end(); it ++)
    {
        if (it->getId() == entityId)
            break;
        i++;
    }
    if (it->getId() == entityId)
        this->movingEntities.*/
}

void MoveSystem::update(float dt)
{
    
}