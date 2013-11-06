//
//  SceneManager.cpp
//  Reflex
//
//  Created by Eric Giraud on 01/11/2013.
//
//

#include "SceneManager.h"
USING_NS_CC;

SceneManager* SceneManager::m_instance = NULL;

SceneManager::SceneManager()
{
}

SceneManager::~SceneManager()
{
    delete pDirector;
    delete pEGLView;
}

SceneManager* SceneManager::Instance()
{
    if (NULL == m_instance)
    {
        m_instance = new SceneManager;
        m_instance->init();
    }
    
    return m_instance;
}

void SceneManager::init()
{
    // initialize director
    pDirector = CCDirector::sharedDirector();
    pEGLView = CCEGLView::sharedOpenGLView();
    
    pDirector->setOpenGLView(pEGLView);
	
    // turn on display FPS
    pDirector->setDisplayStats(true);
    
    // set FPS. the default value is 1.0/60 if you don't call this
    pDirector->setAnimationInterval(1.0 / 60);

}


void SceneManager::startWithScene(CCScene * pScene)
{
    pDirector->runWithScene(pScene);
}

void SceneManager::changeScene(CCScene * pScene)
{
    pDirector->replaceScene(pScene);
}

void SceneManager::showMenu()
{
    std::cout << "chargement du menu\n";
    changeScene(MainMenu::scene());
}

void SceneManager::startGame()
{
    std::cout << "chargement du jeu\n";
    changeScene(GameScene::scene());
}