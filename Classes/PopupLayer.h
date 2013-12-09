//
//  PopupLayer.h
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#ifndef __Reflex__PopupLayer__
#define __Reflex__PopupLayer__

#include <iostream>
#include "cocos2d.h"
#include "Popup.h"
#include "SimpleDelegate.h"
#include "Delegate.h"

class PopupLayer : public cocos2d::CCLayer
{
    private :
    
        bool showLogs;
    
        cocos2d::CCSpriteBatchNode* batchNode;
    
        Delegate *popupQuitDelegate;
    
        Popup *currentPopup;
    
    public :
        CREATE_FUNC(PopupLayer);
    
        PopupLayer();
    
        ~PopupLayer();
    
        virtual bool init();
    
        void finishInit();
    
        void onPopupQuitCallback();
    
        void test(Delegate *delegate);
        void callback();
};

#endif /* defined(__Reflex__PopupLayer__) */
