//
//  PopupFactory.h
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#ifndef __Reflex__PopupFactory__
#define __Reflex__PopupFactory__

#include <iostream>
#include "Popup.h"
#include "cocos2d.h"

class Delegate;
class PopupFactory
{
    public :
    
    static Popup* createPausePopup(std::shared_ptr<Delegate> continueDelegate, std::shared_ptr<Delegate> quitDelegate);
};

#endif /* defined(__Reflex__PopupFactory__) */
/*
int width,
int height,
const char* buttonsImages[],
const function buttonCallbacks[],
const string message,
const string images
*/