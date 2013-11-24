//
//  BoundingSprite.h
//  Reflex
//
//  Created by Eric Giraud on 23/11/2013.
//
//

#ifndef __Reflex__BoundingSprite__
#define __Reflex__BoundingSprite__

#include <iostream>
#include "cocos2d.h"

class BoundingSprite : public cocos2d::CCSprite
{
    private:
        bool showLogs;
        int _radius;
        int _x;
        int _y;
    public:
        BoundingSprite(float r, float x , float y);
        ~BoundingSprite();
        virtual void draw(void);
};

#endif /* defined(__Reflex__BoundingSprite__) */
