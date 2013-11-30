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
}

void UILayer::initUI(World *w)
{
    if (showLogs)
        std::cout << "init UILayer" << std::endl;
    
    this->world = w;
    
    //initialise batchnode and sharesprite
    batchNode = cocos2d::CCSpriteBatchNode::create("gameAtlas.png");
    
    this->addChild(batchNode);
    
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gameAtlas.plist");
    
    cocos2d::CCSprite *sprite = cocos2d::CCSprite::createWithSpriteFrameName("life_empty.png");
    
    sprite->setPosition(ccp(100,100));

    this->addChild(sprite);
}