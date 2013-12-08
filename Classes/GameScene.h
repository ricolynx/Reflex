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
#include "World.h"

class UILayer;
class PopupLayer;
class GameScene : public cocos2d::CCLayer {
    
public :
    
    GameScene();
    
    ~GameScene();
    
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    
    CREATE_FUNC(GameScene);
    
    //virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    
    virtual void registerWithTouchDispatcher();
    
    virtual void ccTouchesBegan(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    virtual void ccTouchesEnded(cocos2d::CCSet* touches, cocos2d::CCEvent* event);
    
    UILayer * uilayer;
    
    PopupLayer *popupLayer;
    
    //the world model of the game (containing the different entities
    World *world;
    
private:
    
    bool showLogs;
    
    //update loop
    void update(float dt);
};

#endif /* defined(__Reflex__GameScene__) */
