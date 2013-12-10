//
//  BlockingLayer.h
//  Reflex
//
//  Created by Eric Giraud on 10/12/2013.
//
//

#ifndef __Reflex__BlockingLayer__
#define __Reflex__BlockingLayer__

#include <iostream>
#include "cocos2d.h"

class BlockingLayer : public cocos2d::CCLayerColor
{
    public:
        BlockingLayer();
        ~BlockingLayer();
    
    private:
        virtual void registerWithTouchDispatcher();
        virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
        bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
};

#endif /* defined(__Reflex__BlockingLayer__) */
