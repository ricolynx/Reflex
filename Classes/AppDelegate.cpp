#include "AppDelegate.h"
#include "MainMenu.h"
#include "SceneManager.h"



USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

bool AppDelegate::applicationDidFinishLaunching() {
    
    //flury
    pFlurry = dynamic_cast<plugin::ProtocolAnalytics*>(plugin::PluginManager::getInstance()->loadPlugin("AnalyticsFlurry"));
    pFlurry->startSession("29SGY6STFJK3N4Q2M2B5");
    
    SceneManager* sm = SceneManager::Instance();
    
    CCScene *pScene = MainMenu::scene();

    sm->startWithScene(pScene);

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    pFlurry->stopSession();
    plugin::PluginManager::getInstance()->unloadPlugin("AnalyticsFlurry");
    pFlurry = NULL;
    
    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    
    pFlurry = dynamic_cast<plugin::ProtocolAnalytics*>(plugin::PluginManager::getInstance()->loadPlugin("AnalyticsFlurry"));
    pFlurry->startSession("29SGY6STFJK3N4Q2M2B5");
    
    CCDirector::sharedDirector()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}
