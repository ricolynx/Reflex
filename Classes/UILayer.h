//
//  UILayer.h
//  Reflex
//
//  Created by Eric Giraud on 30/11/2013.
//
//

#ifndef __Reflex__UILayer__
#define __Reflex__UILayer__

#include <iostream>
#include "cocos2d.h"
#include "UIGage.h"


class World;

class UILayer : public cocos2d::CCLayer
{
    private:
        bool showLogs;
    
        World *world;
    
        cocos2d::CCSpriteBatchNode* batchNode;
    
        UIGage *lifeGage;
        UIGage *ammoGage;
    
    public:
        CREATE_FUNC(UILayer);
        UILayer();
        virtual ~UILayer();
        void initUI(World *w);
};

#endif /* defined(__Reflex__UILayer__) */
