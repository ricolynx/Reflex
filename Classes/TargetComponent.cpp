//
//  TargetComponent.cpp
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#include "TargetComponent.h"


    //Constructor
    component::TargetComponent::TargetComponent(Entity *t)
    {
        this->setNewTarget(t);
    }

    //Destructor
    component::TargetComponent::~TargetComponent()
    {
        this->myTarget = 0;
    }

    //get the target
    Entity* component::TargetComponent::getTarget()
    {
        return this->myTarget;
    }

    //set a new target
    void component::TargetComponent::setNewTarget(Entity *t)
    {
        this->myTarget = t;
    }
