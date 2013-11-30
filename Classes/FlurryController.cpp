//
//  FlurryController.cpp
//  Reflex
//
//  Created by Eric Giraud on 30/11/2013.
//
//

#include "FlurryController.h"

USING_NS_CC;

FlurryController* FlurryController::_instance = 0;

//constructor
FlurryController::FlurryController()
{
    this->showLogs = false;
    if (this->showLogs)
        std::cout << "FlurryController constructor" << std::endl;
    
    pFlurry = dynamic_cast<plugin::ProtocolAnalytics*>(plugin::PluginManager::getInstance()->loadPlugin("AnalyticsFlurry"));
}

//destructor
FlurryController::~FlurryController()
{
    if (this->showLogs)
        std::cout << "FlurryController destructor" << std::endl;
    
    plugin::PluginManager::getInstance()->unloadPlugin("AnalyticsFlurry");
    pFlurry = NULL;
}

//get singleton
FlurryController* FlurryController::Instance()
{
    if (_instance == 0)
    {
        _instance = new FlurryController();
    }
    return _instance;
}

//start a flurry session
void FlurryController::startSession()
{
    if (this->showLogs)
        std::cout << "FlurryController startSession" << std::endl;
    if (pFlurry == 0)
        return;
    pFlurry->startSession("29SGY6STFJK3N4Q2M2B5");
}

//stop the flurry session
void FlurryController::stopSession()
{
    if (this->showLogs)
        std::cout << "FlurryController stopSession" << std::endl;
    if (pFlurry == 0)
        return;
    pFlurry->stopSession();
}

//log a simple event
void FlurryController::logSimpleEvent(const char *eventName)
{
    if (this->showLogs)
        std::cout << "FlurryController log sinmpleEvent : " << eventName << std::endl;
    
    if (pFlurry == 0)
        return;
    
    pFlurry->logEvent(eventName);
}