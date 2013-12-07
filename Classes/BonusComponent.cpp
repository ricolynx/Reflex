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
    this->showLogs = true;
    
    if (this->showLogs)
        std::cout << "Bonus component constructor " << type << std::endl;
    
    this->type = newType;
}

//Destructor
component::BonusComponent::~BonusComponent()
{
    if (this->showLogs)
        std::cout << "Bonus component destructor " << type << std::endl;
    
}


//get the bonus type
component::BonusComponent::BONUS_TYPE component::BonusComponent::getType()
{
    return this->type;
}