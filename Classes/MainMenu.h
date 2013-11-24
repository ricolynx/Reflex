//
//  MainMenu.h
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//

#ifndef __Reflex__MainMenu__
#define __Reflex__MainMenu__

#include "cocos2d.h"
#include "SceneManager.h"

class MainMenu : public cocos2d::CCLayer
{
    private :
        bool showLogs;
    
    public :
        virtual bool init();
    
        static cocos2d::CCScene* scene();
    
        void playCallback(CCObject* pSender);
    
        CREATE_FUNC(MainMenu);
};

#endif // __Reflex__MainMenu__
