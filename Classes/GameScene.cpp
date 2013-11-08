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
    std::cout<<"GameScene Constructor"<<std::endl;
}

GameScene::~GameScene()
{
    std::cout<<"GameScene destructor"<<std::endl;
    delete this->world;
}



bool GameScene::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCLabelTTF* pLabel = CCLabelTTF::create("GameScene", "Arial", 24);
    
    // position the label on the center of the screen
    pLabel->setPosition(ccp(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - pLabel->getContentSize().height));
    
    // add the label as a child to this layer
    this->addChild(pLabel, 1);
    
    
    // add a "close" icon to exit the progress. it's an autorelease object
    CCMenuItemImage *pPlayItem = CCMenuItemImage::create(
                                                         "CloseNormal.png",
                                                         "CloseSelected.png",
                                                         this,
                                                         menu_selector(GameScene::menuCallback));
    
	pPlayItem->setPosition(ccp(origin.x + visibleSize.width - pPlayItem->getContentSize().width/2 ,
                               origin.y + pPlayItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pPlayItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);

    //test world...
    this->world = new World();
    this->world->addSpaceship();
    
    
    this->scheduleUpdate();
    
    return true;
}


void GameScene::menuCallback(CCObject *pSender){
    SceneManager::Instance()->showMenu();
    //std::cout << this->world->entities.size() << std::endl;
}


void GameScene::update(float dt)
{
    //std::cout<<"update :"<<dt<<std::endl;
}

