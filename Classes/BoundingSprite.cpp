//
//  BoundingSprite.cpp
//  Reflex
//
//  Created by Eric Giraud on 23/11/2013.
//
//

#include "BoundingSprite.h"



BoundingSprite::BoundingSprite(float r, float x , float y)
{
    std::cout<< "BoundingSprite - Constructor - radius :" << r << std::endl;
    this->_radius = r;
    this->_x = x;
    this->_y = y;
}

BoundingSprite::~BoundingSprite()
{
    std::cout<< "BoundingSprite - Destructor "<< std::endl;
}

void BoundingSprite::draw(void)
{
    cocos2d::ccDrawColor4B(255, 0, 0, 255);
    cocos2d::ccDrawCircle(ccp(this->_x,this->_y), this->_radius, CC_DEGREES_TO_RADIANS(360), 50, false, 1, 1);
}