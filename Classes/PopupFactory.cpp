//
//  PopupFactory.cpp
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#include "PopupFactory.h"
#include "Popup.h"
Popup* PopupFactory::createPopup()
{
    std::cout << "Create popup"<< std::endl;
    return 0;
}

//int width, int height, const char* buttonsImages[],const function buttonCallbacks[], const string message, const string images