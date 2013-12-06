//
//  AmmoComponent.cpp
//  Reflex
//
//  Created by Eric Giraud on 06/12/2013.
//
//

#include "AmmoComponent.h"

//COnstructor
component::AmmoComponent::AmmoComponent(unsigned int max, unsigned int current)
{
    this->showLogs = true;
    
    if (showLogs)
        std::cout << "AmmoComponent constructor" << std::endl;
    
    this->_currentAmmo = current;
    this->_maxAmmo = max;
}

//Destructor
component::AmmoComponent::~AmmoComponent()
{
    if (showLogs)
        std::cout << "AmmoComponent destructor" << std::endl;
}

//shoot (decrease ammo)
void component::AmmoComponent::shoot()
{
    if (this->_currentAmmo > 0)
        this->_currentAmmo --;
}

//recharge all ammo (set current to max)
void component::AmmoComponent::recharge()
{
    this->_currentAmmo = this->_maxAmmo;
}

/*


;

;
*/