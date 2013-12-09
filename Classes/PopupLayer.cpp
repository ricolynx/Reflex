//
//  PopupLayer.cpp
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#include "PopupLayer.h"

//Constructor
PopupLayer::PopupLayer()
{
    this->showLogs = true;
    if (this->showLogs)
        std::cout<< "PopupLayer CTOR" << std::endl;
}

//Destructor
PopupLayer::~PopupLayer()
{
    if (this->showLogs)
        std::cout<< "PopupLayer DTOR" << std::endl;

}

//initfunction (called by the create)
bool PopupLayer::init()
{
    if ( !CCLayer::init() )
    {
        return false;
    }
    return true;
}

void PopupLayer::finishInit()
{
    this->batchNode = cocos2d::CCSpriteBatchNode::create("gameUIAtlas.png");
    this->addChild(batchNode);

}

void PopupLayer::test(Delegate *d)
{
    std::cout<<"test popup"<<std::endl;
    
    
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    std::vector<std::string>  buttonsImages = {"quitbig"};
    std::vector<Delegate*> delegates = {d};
    
    Popup *p = Popup::create();
    p->initPopup(worldSize.width - 300, worldSize.height - 200 ,buttonsImages , delegates, "the message", "");
    p->setPosition(ccp(worldSize.width / 2.0f , worldSize.height / 2.0f ));
    this->addChild(p);
    
    //d->invoke();
}

void PopupLayer::callback()
{
    std::cout<< "test callback"<< std::endl;
}