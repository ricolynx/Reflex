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
    
        std::map<cocos2d::CCMenuItemSprite*, std::shared_ptr<Delegate>> buttons;
    
        void createBackGround();
    
        cocos2d::CCMenuItemSprite* createButton(const std::string image, std::shared_ptr<Delegate>, int index);
    
        void buttonCallBack(CCObject *pSender);
    
        Delegate *onquitCallback;
    
    public:
    
        CREATE_FUNC(Popup);
    
        Popup();
    
        ~Popup();
    
        void initPopup(
                          float w,
                          float h,
                          std::vector<std::string> buttonsImages,
                          std::vector<std::shared_ptr<Delegate>> callbacks,
                          const std::string message,
                          const std::string images
                       );
    
        void setClosePopupDelegate(Delegate *quitDelegate);
};

#endif /* defined(__Reflex__Popup__) */
