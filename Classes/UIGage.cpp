//
//  UIGage.cpp
//  Reflex
//
//  Created by Eric Giraud on 01/12/2013.
//
//

#include "UIGage.h"

//constructor
UIGage::UIGage()
{
    this->showLogs = true;
    if (this->showLogs)
        std::cout << "UIGage Constructor " << this << std::endl;
    
    this->_isInitialized = false;
}

//destructor
UIGage::~UIGage()
{
    if (this->showLogs)
        std::cout << "UIGage Destructor " << _frontName <<" " << this << std::endl;
    
    this->_frontName = 0;
    
    //clean references of front sprites of the gauge (stored in list)
    while (this->_currentValue != 0)
    {
        --(*this);
    }
    
    this->removeAllChildrenWithCleanup(true);
}

//init function
void UIGage::initGage(int max, int current, const char* bgName, const char* frontName)
{
    if (this->_isInitialized)
    {
        std::cout << "Gage is already initialized" << std::endl;
        return ;
    }
    
    this->_isInitialized = true;
    
    this->_maxValue = max;

    this->_currentValue = 0;
    
    this->_frontName = frontName;
    
    this->createBackground(bgName);
    
    while (this->_currentValue != current)
    {
      ++(*this);
    }
}

//operator o++
UIGage& UIGage::operator++ ()
{
    if (this->_currentValue < this->_maxValue)
    {
        this->graphicIncrement();
        this->_currentValue++;
    }
    return *this;
}

//operator o--
UIGage& UIGage::operator-- ()
{
    if (this->_currentValue > 0)
    {
        this->graphicDecrement();
        this->_currentValue --;
    }
    return *this;
}

//create the background
void UIGage::createBackground(const char* spriteName)
{
    for (int i = 0; i < this->_maxValue; i++)
    {
        this->addSprite(spriteName, i);
    }
}

//graphicaly increment the gage
void UIGage::graphicIncrement()
{
    if (this->_currentValue >= this->_maxValue)
        return;
    
    cocos2d::CCSprite *sprite = this->addSprite(this->_frontName,this->_currentValue);
    this->_frontSprites.push_back(sprite);
}

//graphicaly decrement the gage
void UIGage::graphicDecrement()
{
    if (this->_currentValue == 0)
        return;
    
    this->removeChild( this->_frontSprites.back(), true);
    this->_frontSprites.pop_back();
}

//add a sprite to the gage
cocos2d::CCSprite* UIGage::addSprite(const char* name , int index)
{
    cocos2d::CCSprite *sprite = cocos2d::CCSprite::createWithSpriteFrameName(name);
    float posx = (sprite->getContentSize().width + DELTA) * index;
    float posy = 0;
    sprite->setPosition(ccp(posx,posy));
    this->addChild(sprite);

    return sprite;
}

//get the current value of the gage
unsigned int UIGage::getValue()
{
    return this->_currentValue;
}
