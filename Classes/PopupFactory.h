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

class PopupFactory
{
    public :
    
        static Popup* createPopup();
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