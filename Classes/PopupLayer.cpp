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
    
    this->popupQuitDelegate = new SimpleDelegate<PopupLayer>(this, &PopupLayer::onPopupQuitCallback);
    this->currentPopup = 0;
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

void PopupLayer::onPopupQuitCallback()
{
    if (this->currentPopup  !=0)
    {
        std::cout<< "on quit popup" << std::endl;
        this->removeChild(this->currentPopup);
    }
}

void PopupLayer::test(Delegate *d)
{
    std::cout<<"test popup"<<std::endl;
    
    
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    std::vector<std::string>  buttonsImages = {"quitbig","quitbig"};
    std::vector<Delegate*> delegates = {d,d};
    
    Popup *p = Popup::create();
    p->initPopup(worldSize.width - 300,
                 worldSize.height - 200 ,
                 buttonsImages ,
                 delegates,
                 "the message",
                 "",
                 this->popupQuitDelegate
                 );
    
    p->setPosition(ccp(worldSize.width / 2.0f , worldSize.height / 2.0f ));
    this->addChild(p);
    this->currentPopup = p;
}

void PopupLayer::callback()
{
    std::cout<< "test callback"<< std::endl;
}