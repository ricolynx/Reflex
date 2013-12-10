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
    if (this->popupQuitDelegate)
    {
        delete this->popupQuitDelegate;
        this->popupQuitDelegate = 0;
    }
    
    if (this->blockingLayer)
        this->blockingLayer = 0;

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

//finish init of PopupLayer
void PopupLayer::finishInit()
{
    this->batchNode = cocos2d::CCSpriteBatchNode::create("gameUIAtlas.png");
    this->addChild(batchNode);
}


//show a popup
void PopupLayer::showPopup(Popup *popup)
{
    popup->setClosePopupDelegate(this->popupQuitDelegate);
    
    //->lock the background
    this->blockingLayer = new BlockingLayer();
    this->addChild(this->blockingLayer);
    
    //add the popup
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    popup->setPosition(ccp(worldSize.width / 2.0f , worldSize.height / 2.0f ));
    this->addChild(popup);
    this->currentPopup = popup;
}


//quit callback (when user quit a popup)
void PopupLayer::onPopupQuitCallback()
{
    if (this->currentPopup  !=0)
    {
        std::cout<< "on quit popup" << std::endl;
        this->removeChild(this->currentPopup);
    }
    
    if (this->blockingLayer)
    {
        this->removeChild(this->blockingLayer);
        this->blockingLayer = 0;
    }
}

