//
//  UIGage.h
//  Reflex
//
//  Created by Eric Giraud on 01/12/2013.
//
//

#ifndef __Reflex__UIGage__
#define __Reflex__UIGage__

#include <iostream>
#include "cocos2d.h"

#define DELTA 10

class UIGage : public cocos2d::CCSprite
{
    private:
    
        bool showLogs;
    
        bool _isInitialized;
    
        unsigned int _maxValue;
    
        unsigned int _currentValue;
    
        const char *_frontName;
    
        std::vector<cocos2d::CCSprite*> _frontSprites;
    
        void createBackground(const char* spriteName);
    
        void graphicIncrement();
    
        void graphicDecrement();
    
        cocos2d::CCSprite* addSprite(const char* name , int index);
    
    public:
    
        CREATE_FUNC(UIGage);
    
        UIGage();
    
        virtual ~UIGage();
    
        unsigned int getValue();
    
        void initGage(int max, int current, const char* bgName, const char* frontName);
    
        UIGage& operator++ ();
        UIGage& operator-- ();
};

#endif /* defined(__Reflex__UIGage__) */
