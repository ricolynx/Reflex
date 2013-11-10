//
//  WorldView.h
//  Reflex
//
//  Created by Eric Giraud on 10/11/2013.
//
//

#ifndef __Reflex__WorldView__
#define __Reflex__WorldView__

#include <iostream>

#include "cocos2d.h"
#include "World.h"


class WorldView
{
private:
    
    World *worldModel;
    
    cocos2d::CCLayer *scene;
    
    cocos2d::CCSpriteBatchNode* _batchNode;
    
public:
    WorldView(cocos2d::CCLayer* s, World* w);
    ~WorldView();
    
    void addEntity();
};


#endif /* defined(__Reflex__WorldView__) */
