//
//  UILayer.cpp
//  Reflex
//
//  Created by Eric Giraud on 30/11/2013.
//
//

#include "UILayer.h"
USING_NS_CC;

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

bool UILayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    
    this->scheduleUpdate();
    
    return true;
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
    
    this->createMenuButton();
    
}

// create the menu buttons
void UILayer::createMenuButton()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCMenuItemSprite *pQuitItem= CCMenuItemSprite::create(
                                                       CCSprite::createWithSpriteFrameName("quit.png"),
                                                       CCSprite::createWithSpriteFrameName("quit_selected.png"),
                                                       this,
                                                       menu_selector(UILayer::quitHandler)
                                                          );
    
    pQuitItem->setPosition(ccp(origin.x + visibleSize.width - pQuitItem->getContentSize().width/2 - 10,
                               origin.y + pQuitItem->getContentSize().height/2 + 10) );
    
    
    CCMenuItemSprite *pPauseItem= CCMenuItemSprite::create(
                                                          CCSprite::createWithSpriteFrameName("pause.png"),
                                                          CCSprite::createWithSpriteFrameName("pause_selected.png"),
                                                          this,
                                                          menu_selector(UILayer::pauseHandler)
                                                          );
    
    pPauseItem->setPosition(ccp(pQuitItem->getPosition().x - pPauseItem->getContentSize().width -10,
                               origin.y + pPauseItem->getContentSize().height/2 + 10) );
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pQuitItem, NULL);
    pMenu->addChild(pPauseItem);
    
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu);
}

void UILayer::pauseHandler(CCObject *pSender)
{
    this->world->pauseGame();
}

void UILayer::quitHandler(CCObject *pSender)
{
    SceneManager::Instance()->showMenu();
}

//update loop
void UILayer::update(float dt)
{
    if (this->world!=0 && this->lifeGage!=0 && this->world->canon!=0)
    {
        if (this->lifeGage->getValue() > this->world->getLives())
        {
            std::cout << "decrease life " << std::endl;
            --(*(this->lifeGage));
        }
        else if (this->lifeGage->getValue() < this->world->getLives())
        {
            std::cout << "decrease life " << std::endl;
            ++(*(this->lifeGage));
        }
        
        if (this->ammoGage->getValue() > this->world->canon->getComponent<component::AmmoComponent>()->getAmmo())
        {
            --(*(this->ammoGage));
        }else if (this->ammoGage->getValue() < this->world->canon->getComponent<component::AmmoComponent>()->getAmmo())
        {
            ++(*(this->ammoGage));
        }
        
    }
}

