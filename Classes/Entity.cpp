//
//  Entity.cpp
//  Reflex
//
//  Created by Eric Giraud on 04/11/2013.
//
//

#include "Entity.h"


//Constructor
Entity::Entity(int newId, ENTITY_TYPE newType)
{
    this->Id = newId;
    
    this->type = newType;
    
}


Entity::~Entity()
{
}

//get the id of the entity
int Entity::getId()
{
    return this->Id;
}