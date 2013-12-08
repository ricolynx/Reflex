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
#include "SimpleDelegate.h"
#include "Popup.h"
#include "Delegate.h"

class PopupLayer : public cocos2d::CCLayer
{
    private :
    
        bool showLogs;
    
        cocos2d::CCSpriteBatchNode* batchNode;
    
    public :
        CREATE_FUNC(PopupLayer);
    
        PopupLayer();
    
        ~PopupLayer();
    
        virtual bool init();
    
        void finishInit();
    
        void test(Delegate *delegate);
        void callback();
};

#endif /* defined(__Reflex__PopupLayer__) */
