//
//  GameScene.cpp
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//

#include "GameScene.h"
#include "UILayer.h"
USING_NS_CC;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // main layer
    GameScene *layer = GameScene::create();
    
    UILayer *uiLayer = UILayer::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    scene->addChild(uiLayer);
    
    layer->uilayer = uiLayer;
    
    layer->uilayer->initUI(layer->world);
    
    // return the scene
    return scene;
}

GameScene::GameScene()
{
    showLogs = false;
    if (showLogs)
        std::cout<<"GameScene Constructor"<<std::endl;
}

GameScene::~GameScene()
{
    if (showLogs)
        std::cout<<"GameScene destructor"<<std::endl;
    
    this->uilayer = 0;
    
    delete this->world;
}



bool GameScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
   
    //test world...
    this->world = new World(this);
    
    this->scheduleUpdate();
    
    this->setTouchEnabled(true);
    
    return true;
}

void GameScene::update(float dt)
{
    this->world->update(dt);
}

void GameScene::ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event)
{
    if (showLogs)
        std::cout << "TOUCH began" << std::endl;
    
    this->world->onTouchesBegan(touches);
}

void GameScene::ccTouchesEnded(CCSet* touches, CCEvent* event)
{
    if (showLogs)
        std::cout << "TOUCH Ended" << std::endl;
    
    this->world->onTouchesEnded(touches);
}


void GameScene::registerWithTouchDispatcher()
{
    CCDirector::sharedDirector()->getTouchDispatcher()->addStandardDelegate(this, 0);
}

