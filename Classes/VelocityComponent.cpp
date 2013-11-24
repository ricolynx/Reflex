//
//  VelocityComponent.cpp
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#include "VelocityComponent.h"

//constructor
component::VelocityComponent::VelocityComponent()
{
    showLogs = false;
    if (showLogs)
        std::cout<<"velocity component constructor"<< std::endl;
    
    this->speedX = 0;
    this->speedY = 0;
}

//destructor
component::VelocityComponent::~VelocityComponent()
{
    if (showLogs)
        std::cout<<"velocity component destructor"<< std::endl;
}