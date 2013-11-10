//
//  WorldView.cpp
//  Reflex
//
//  Created by Eric Giraud on 10/11/2013.
//
//

#include "WorldView.h"

//Constructor
WorldView::WorldView(cocos2d::CCLayer* s, World* w)
{
    std::cout << "WorldView constructor " << std::endl;
    scene = s;
    worldModel = w;
    
    _batchNode = cocos2d::CCSpriteBatchNode::create("Sprites.pvr.ccz");
    scene->addChild(_batchNode);
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Sprites.plist");
}

WorldView::~WorldView()
{
    std::cout << "WorldView destructor" << std::endl;
}


void WorldView::addEntity()
{
    cocos2d::CCSprite *psprite = cocos2d::CCSprite::createWithSpriteFrameName("SpaceFlier_sm_1.png");
    
    cocos2d::CCSize winSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    psprite->setPosition(ccp(winSize.width * 0.1, winSize.height * 0.5));
    this->scene->addChild(psprite);
    
    this->worldModel->addSpaceship();
}