//
//  Popup.cpp
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#include "Popup.h"


USING_NS_CC;

Popup::Popup()
{
    this->showLogs = true;
    
    if (this->showLogs)
        std::cout << "Popup Constructor" << std::endl;
}


void Popup::initPopup(float w,
             float h,
             std::vector<std::string>  buttonsImages,
             std::vector<Delegate*> callbacks,
             const std::string message,
             const std::string images)
{
    if (buttonsImages.size() != callbacks.size())
    {
        std::cout << "Error for popup initialisation : number of buttons not equal to number of callbacks" << std::endl;
        return;
    }
    
    this->width = w;
    
    this->height = h;
    
    this->createBackGround();

    //->create the buttons
}

Popup::~Popup()
{
    if (this->showLogs)
        std::cout << "Popup Destructor" << std::endl;
}

void Popup::createBackGround()
{
    this->bg = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName("9-grid.png", CCRectMake(20, 20, 40, 40));
    this->bg->setContentSize(CCSizeMake(this->width, this->height));
    this->addChild(this->bg);
}

void Popup::addButon(const std::string image, Delegate *callback)
{
    
}

void Popup::buttonCallBack(CCObject *pSender)
{
    
}
