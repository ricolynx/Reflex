//
//  Popup.h
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#ifndef __Reflex__Popup__
#define __Reflex__Popup__

#include <iostream>
#include <unordered_map>
#include "cocos2d.h"
#include "CCScale9Sprite.h"

#include "Delegate.h"

class Popup : public cocos2d::CCSprite
{
    private:
        bool showLogs;
    
        int nbButtons;
    
        float width;
    
        float height;
    
        cocos2d::extension::CCScale9Sprite *bg;
    
        cocos2d::CCLabelTTF *text;
    
        cocos2d::CCSprite *img;
    
        std::unordered_map<cocos2d::CCMenuItemSprite*, Delegate*> buttons;
    
        void createBackGround();
    
        cocos2d::CCMenuItemSprite* createButton(const std::string image, Delegate *callback, int index);
    
        void buttonCallBack(CCObject *pSender);
    
        Delegate *onquitCallback;
    
    public:
    
        CREATE_FUNC(Popup);
    
        Popup();
    
        void initPopup(
                          float w,
                          float h,
                          std::vector<std::string> buttonsImages,
                          std::vector<Delegate*> callbacks,
                          const std::string message,
                          const std::string images,
                          Delegate *onClickCallback
                       );
    
        ~Popup();
};

#endif /* defined(__Reflex__Popup__) */
