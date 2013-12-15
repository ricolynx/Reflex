//
//  LifeComponent.cpp
//  Reflex
//
//  Created by Eric Giraud on 17/11/2013.
//
//

#include "LifeComponent.h"

//Constructor
component::LifeComponent::LifeComponent(int l)
{
    showLogs = false;
    
    if (showLogs)
        std::cout<<"life component constructor"<< std::endl;
    
    this->maxLife = l;
    this->life = l;
}

//Destructor
component::LifeComponent::~LifeComponent()
{
    if (showLogs)
        std::cout<<"life component destructor"<< std::endl;
}

int component::LifeComponent::getMaxLife()
{
    return this->maxLife;
}

//operator o++
component::LifeComponent& component::LifeComponent::operator++ ()
{
    if (this->life < this->maxLife)
    {
        ++this->life;
    }
    return *this;
}

//operator o--
component::LifeComponent& component::LifeComponent::operator-- ()
{
    if (this->life > 0)
    {
        -- this->life;
    }
    return *this;
}