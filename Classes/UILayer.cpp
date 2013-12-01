//
//  UILayer.cpp
//  Reflex
//
//  Created by Eric Giraud on 30/11/2013.
//
//

#include "UILayer.h"


UILayer::UILayer()
{
    showLogs = true;
    
    if (showLogs)
        std::cout << "constructor UILayer" << std::endl;
    
    this->world = 0;
}

UILayer::~UILayer()
{
    if (showLogs)
        std::cout << "destructor UILayer" << std::endl;
    
    if (this->world !=0)
        this->world = 0;
    
    this->batchNode = 0;
    
    this->removeChild(this->lifeGage,true);
    this->lifeGage = 0;
    
    this->removeChild(this->ammoGage,true);
    this->ammoGage = 0;
}

void UILayer::initUI(World *w)
{
    if (showLogs)
        std::cout << "init UILayer" << std::endl;
    
    this->world = w;
    
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    //initialise batchnode and sharesprite
    this->batchNode = cocos2d::CCSpriteBatchNode::create("gameUIAtlas.png");
    this->addChild(batchNode);
    
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gameUIAtlas.plist");
    
    this->lifeGage = UIGage::create();
    this->addChild(lifeGage);
    
    this->ammoGage = UIGage::create();
    this->addChild(ammoGage);
    
    this->lifeGage->setPosition(ccp( 50, worldSize.height - 50));
    this->lifeGage->initGage(3,3,"life_empty.png","life.png");
    

    this->ammoGage->initGage(3,3,"ammo_empty.png","ammo.png");
    this->ammoGage->setPosition(ccp( worldSize.width - 50 - 90 , worldSize.height - 50));
}


