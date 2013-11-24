//
//  GameScene.cpp
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//

#include "GameScene.h"
USING_NS_CC;

CCScene* GameScene::scene()
{
    // 'scene' is an autorelease object
    CCScene *scene = CCScene::create();
    
    // 'layer' is an autorelease object
    GameScene *layer = GameScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
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
    
    delete this->world;
}



bool GameScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    initUI();
    
    //test world...
    this->world = new World(this);
    
    this->scheduleUpdate();
    
    this->setTouchEnabled(true);
    
    return true;
}

void GameScene::initUI()
{
 
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    /*
    CCLabelTTF* pLabel = CCLabelTTF::create("GameScene", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
     */
    
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pPlayItem = CCMenuItemImage::create(
                                                         "CloseNormal.png",
                                                         "CloseSelected.png",
                                                         this,
                                                         menu_selector(GameScene::menuCallback));
    
	pPlayItem->setPosition(ccp(origin.x + visibleSize.width - pPlayItem->getContentSize().width/2 ,
                               origin.y + pPlayItem->getContentSize().height/2));
    
    
    CCMenuItemImage *pTestItem = CCMenuItemImage::create(
                                                         "TestNormal.png",
                                                         "TestSelected.png",
                                                         this,
                                                         menu_selector(GameScene::testCallback));
    
	pTestItem->setPosition(ccp(origin.x + visibleSize.width - 2 * pTestItem->getContentSize().width  ,
                               origin.y + pTestItem->getContentSize().height/2));

    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pPlayItem, NULL);
    pMenu->addChild(pTestItem);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
}

void GameScene::testCallback(CCObject *pSender)
{
    //std::cout << this->world->getNbEntities() << std::endl;
    //this->worldView->addEntity();
}

void GameScene::menuCallback(CCObject *pSender)
{
    SceneManager::Instance()->showMenu();
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

