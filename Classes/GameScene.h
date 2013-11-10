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
#include "WorldView.h"

class GameScene : public cocos2d::CCLayer {
    
public :
    
    GameScene();
    
    ~GameScene();
    
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    
    CREATE_FUNC(GameScene);
    
    
private:
    
    //the world model of the game (containing the different entities
    World *world;
    
    //represent the world view of the game
    WorldView *worldView;
    
    //initialisation of the menu
    void initUI();
    
    //callback for the test button
    void testCallback(CCObject* pSender);
    
    //menu callback
    void menuCallback(CCObject* pSender);
    
    //update loop
    void update(float dt);
};

#endif /* defined(__Reflex__GameScene__) */
