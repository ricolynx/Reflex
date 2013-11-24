//
//  SceneManager.h
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//

#ifndef __Reflex__SceneManager__
#define __Reflex__SceneManager__

#include "cocos2d.h"
#include "MainMenu.h"
#include "GameScene.h"

class SceneManager
{
private:
    
    bool showLogs;
    
    static SceneManager* m_instance;
    
    cocos2d::CCDirector* pDirector;
    cocos2d::CCEGLView* pEGLView;
    
    SceneManager();
    virtual ~SceneManager();
    
    void init();
    

    
public:
   
    
    static SceneManager* Instance();
    
    void startWithScene(cocos2d::CCScene *);
    
    void changeScene(cocos2d::CCScene *);
    
    void showMenu();
    
    void startGame();
    
};

#endif /* defined(__Reflex__SceneManager__) */
