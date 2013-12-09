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


void Popup::initPopup(float w,
             float h,
             std::vector<std::string>  buttonsImages,
             std::vector<Delegate*> callbacks,
             const std::string message,
             const std::string images)
{
    if (buttonsImages.size() != callbacks.size())
    {
        std::cout << "Error for popup initialisation : number of buttons not equal to number of callbacks" << std::endl;
        return;
    }
    
    this->nbButtons = buttonsImages.size();
    
    this->width = w;
    
    this->height = h;
    
    this->createBackGround();

    //->create the buttons
    CCMenu* pMenu ;
    for (int i = 0; i< buttonsImages.size() ; i++)
    {
        if (i==0)
            pMenu= CCMenu::create( this->createButton( buttonsImages[i], callbacks [i]) , NULL);
        else
            pMenu->addChild(this->createButton( buttonsImages[i], callbacks [i]));
        
    }
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu);
}

Popup::~Popup()
{
    if (this->showLogs)
        std::cout << "Popup Destructor" << std::endl;
}

void Popup::createBackGround()
{
    this->bg = cocos2d::extension::CCScale9Sprite::createWithSpriteFrameName("9-grid.png", CCRectMake(20, 20, 40, 40));
    this->bg->setContentSize(CCSizeMake(this->width, this->height));
    this->addChild(this->bg);
}

CCMenuItemSprite* Popup::createButton(const std::string image, Delegate *callback)
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
    
    
    //-->reference it in the buttons hashtable
    this->buttons.emplace(pItem,callback);
    
    return pItem;
}

/*
CCMenuItemSprite *pQuitItem= CCMenuItemSprite::create(
                                                      CCSprite::createWithSpriteFrameName("quit.png"),
                                                      CCSprite::createWithSpriteFrameName("quit_selected.png"),
                                                      this,
                                                      menu_selector(UILayer::quitHandler)
                                                      );

pQuitItem->setPosition(ccp(origin.x + visibleSize.width - pQuitItem->getContentSize().width/2 - 10,
                           origin.y + pQuitItem->getContentSize().height/2 + 10) );

 
 // create menu, it's an autorelease object
 = CCMenu::create(pQuitItem, NULL);
 pMenu->addChild(pPauseItem);
 

*/

void Popup::buttonCallBack(CCObject *pSender)
{
    std::cout << "button callback" << std::endl;

    this->buttons[dynamic_cast<CCMenuItemSprite*>(pSender)]->invoke();
    
}
