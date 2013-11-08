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
    std::cout << "entity " << newId << " constructor" << std::endl;
    
    this->Id = newId;
    
    this->type = newType;
    
}


Entity::~Entity()
{
    std::cout << "entity " << this->Id << " destructor" << std::endl;
}

//get the id of the entity
int Entity::getId()
{
    return this->Id;
}