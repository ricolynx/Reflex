//
//  BlockingLayer.cpp
//  Reflex
//
//  Created by Eric Giraud on 10/12/2013.
//
//

#include "BlockingLayer.h"
USING_NS_CC;
BlockingLayer::BlockingLayer()
{
    cocos2d::CCLayerColor::initWithColor(ccc4(255,255,255,20));
    setTouchEnabled(true);
}

BlockingLayer::~BlockingLayer()
{
    setTouchEnabled(false);
}

void BlockingLayer::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    
}

bool BlockingLayer::ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent)
{
    return true;
}

void BlockingLayer::registerWithTouchDispatcher()
{
    cocos2d::CCDirector::sharedDirector()->getTouchDispatcher()->addTargetedDelegate(this, -200, true);
}