//
//  PopupFactory.cpp
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#include "PopupFactory.h"
#include "Popup.h"
Popup* PopupFactory::createPausePopup(std::shared_ptr<Delegate> continueDelegate, std::shared_ptr<Delegate> quitDelegate)
{
    std::cout << "Create popup pause"<< std::endl;
    
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    std::vector<std::string>  buttonsImages = {"play","quitbig"};
    std::vector<std::shared_ptr<Delegate>> delegates = {continueDelegate,quitDelegate};
    
    Popup *p = Popup::create();
    p->initPopup(worldSize.width - 300,
                 worldSize.height - 200 ,
                 buttonsImages ,
                 delegates,
                 "PAUSE",
                 100,
                 ""
                 );

    
    return p;
}

//int width, int height, const char* buttonsImages[],const function buttonCallbacks[], const string message, const string images