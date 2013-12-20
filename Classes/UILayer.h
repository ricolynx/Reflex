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
#include "World.h"
#include "SceneManager.h"
#include "ScoreObserver.h"


class UILayer : public cocos2d::CCLayer, public ScoreObserver
{
    private:
        bool showLogs;
    
        World *world;
    
        cocos2d::CCSpriteBatchNode* batchNode;
    
        // life gage
        UIGage *lifeGage;
    
        //ammo gage
        UIGage *ammoGage;
    
        cocos2d::CCLabelTTF* score;
    
        //create the menu buttons
        void createMenuButton();
    
        //handler for click on pause button
        void pauseHandler(CCObject *pSender);
    
        //handler for click on quit button
        void quitHandler(CCObject *pSender);
    
        //update loop
        void update(float dt);
    
    public:
    
        CREATE_FUNC(UILayer);
    
        UILayer();
    
        virtual ~UILayer();
    
        void initUI(World *w);
    
        virtual bool init();
    
        void update (ScoreAction action, int newScore);
};

#endif /* defined(__Reflex__UILayer__) */
