//
//  MainMenu.cpp
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//
#include "MainMenu.h"
USING_NS_CC;


CCScene* MainMenu::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    MainMenu *layer = MainMenu::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


// on "init" you need to initialize your instance
bool MainMenu::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.
    
    // add a "close" icon to exit the progress. it's an autorelease object
    
    
    /////////////////////////////
    // 3. add your codes below...
    
    // add a label shows "Hello World"
    // create and initialize a label
    /*
    CCLabelTTF* pLabel = CCLabelTTF::create("MainMenu", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);*/
    
    /*
    // add "HelloWorld" splash screen"
    CCSprite* pSprite = CCSprite::create("HelloWorld.png");
    
    // position the sprite on the center of the screen
    pSprite->setPosition(ccp(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    
    // add the sprite as a child to this layer
    this->addChild(pSprite, 0);*/
    
    
    
    this->batchNode = cocos2d::CCSpriteBatchNode::create("mainMenuAtlas.png");
    this->addChild(batchNode);
    
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("mainMenuAtlas.plist");
    
    
    CCMenuItemSprite *pPlayItem = CCMenuItemSprite::create(
                                                         cocos2d::CCSprite::createWithSpriteFrameName("play.png"),
                                                         cocos2d::CCSprite::createWithSpriteFrameName("play_selected.png"),
                                                         this,
                                                         menu_selector(MainMenu::playCallback));
    
	pPlayItem->setPosition(ccp(origin.x + visibleSize.width / 2 ,
                               origin.y + visibleSize.height / 2 ));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pPlayItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    
    return true;
}


void MainMenu::playCallback(CCObject *pSender){
    SceneManager::Instance()->startGame();
}








