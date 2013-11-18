//
//  TargetComponent.cpp
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#include "TargetComponent.h"


//Constructor
component::TargetComponent::TargetComponent(std::shared_ptr<Entity> t)
{
    std::cout<<"target component constructor"<< std::endl;
    this->setNewTarget(t);
}

//Destructor
component::TargetComponent::~TargetComponent()
{
    std::cout<<"target component destructor"<< std::endl;
    this->myTarget = 0;
}

//get the target
std::shared_ptr<Entity> component::TargetComponent::getTarget()
{
    return this->myTarget;
}

//set a new target
void component::TargetComponent::setNewTarget(std::shared_ptr<Entity> t)
{
    this->myTarget = t;
}
