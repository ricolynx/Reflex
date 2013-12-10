//
//  BonusComponent.cpp
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#include "BonusComponent.h"

//CTOR
component::BonusComponent::BonusComponent(BONUS_TYPE newType)
{
    this->showLogs = false;
    
    if (this->showLogs)
        std::cout << "Bonus component constructor " << newType << std::endl;
    
    this->type = newType;
}

//Destructor
component::BonusComponent::~BonusComponent()
{
    if (this->showLogs)
        std::cout << "Bonus component destructor " << std::endl;
    
}


//get the bonus type
component::BonusComponent::BONUS_TYPE component::BonusComponent::getType()
{
    return this->type;
}