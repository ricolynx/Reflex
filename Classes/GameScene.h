//
//  GameScene.h
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//

#ifndef __Reflex__GameScene__
#define __Reflex__GameScene__

#include "cocos2d.h"
#include "SceneManager.h"


class GameScene : public cocos2d::CCLayer
{
    public :
        virtual bool init();
    
        static cocos2d::CCScene* scene();
    
        void menuCallback(CCObject* pSender);
    
        CREATE_FUNC(GameScene);
};

#endif /* defined(__Reflex__GameScene__) */
