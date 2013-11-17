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
    std::cout<<"life component constructor"<< std::endl;
    life = l;
}

//Destructor
component::LifeComponent::~LifeComponent()
{
    std::cout<<"life component destructor"<< std::endl;
}