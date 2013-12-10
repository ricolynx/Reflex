//
//  Popup.cpp
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#include "Popup.h"


USING_NS_CC;

Popup::Popup()
{
    this->showLogs = true;
    
    if (this->showLogs)
        std::cout << "Popup Constructor" << std::endl;
    
    
}


Popup::~Popup()
{
    if (this->showLogs)
        std::cout << "Popup Destructor" << std::endl;
    
    //-> clean delegates
    this->buttons.clear();
    
    //->clean ref to bg, text and img
    this->bg = 0;
    this->text = 0;
    this->img = 0;
    this->onquitCallback = 0;
}

void Popup::initPopup(float w,
             float h,
             std::vector<std::string>  buttonsImages,
             std::vector<std::shared_ptr<Delegate>> callbacks,
             const std::string message,
             const std::string images
                      )
{
    if (buttonsImages.size() != callbacks.size())
    {
        std::cout << "Error for popup initialisation : number of buttons not equal to number of callbacks" << std::endl;
        return;
    }
    
    this->onquitCallback = 0;
    
    this->nbButtons = buttonsImages.size();
    
    this->width = w;
    
    this->height = h;
    
    this->createBackGround();

    //->create the buttons
    
    CCMenu* pMenu ;
    for (int i = 0; i< buttonsImages.size() ; i++)
    {
        if (i==0)
            pMenu= CCMenu::create( this->createButton( buttonsImages[i], callbacks [i], i) , NULL);
        else
            pMenu->addChild(this->createButton( buttonsImages[i], callbacks [i], i));
        
    }
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu);
    pMenu->setTouchPriority(-201);
}

void Popup::setClosePopupDelegate(Delegate *quitDelegate)
{
    this->onquitCallback = quitDelegate;
}

void Popup::createBackGround()
{
    this->bg = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName("9-grid.png", CCRectMake(20, 20, 40, 40));
    this->bg->setContentSize(CCSizeMake(this->width, this->height));
    this->addChild(this->bg);
}

CCMenuItemSprite* Popup::createButton(const std::string image, std::shared_ptr<Delegate> callback, int index)
{
    //-->create the button
    const std::string normal = image + ".png";
    const std::string selected = image + "_selected.png";
    
    CCMenuItemSprite *pItem= CCMenuItemSprite::create(
                                                      CCSprite::createWithSpriteFrameName(normal.c_str()),
                                                      CCSprite::createWithSpriteFrameName(selected.c_str()),
                                                      this,
                                                      menu_selector(Popup::buttonCallBack)
                                                      );
    //-->set right position
    std::cout<<(this->width / this->nbButtons) * (index)<<" " << index <<std::endl;
    
    pItem->setPosition(ccp(
                              - this->width/2 + (this->width / this->nbButtons) * (index) + (this->width / this->nbButtons) /2,
                              - this->height/2 + pItem->getContentSize().height / 2 + 40
                           ));
    
    //-->reference it in the buttons hashtable
    this->buttons.emplace(pItem,callback);
    
    return pItem;
}

void Popup::buttonCallBack(CCObject *pSender)
{
    std::cout << "button callback" << std::endl;

    this->buttons[dynamic_cast<CCMenuItemSprite*>(pSender)]->invoke();
    
    if (this->onquitCallback != 0)
        onquitCallback->invoke();
}
