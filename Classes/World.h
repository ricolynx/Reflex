//
//  World.h
//  Reflex
//
//  Created by Eric Giraud on 06/11/2013.
//
//

#ifndef __Reflex__World__
#define __Reflex__World__

#include <list>
#include <iostream>

#include "Entity.h"

class World
{
private :
    
    
    bool addEntity(Entity*);
    
public :
    
    World();
    ~World();

    void init();
    
    bool addSpaceship();
    
    std::list<Entity> entities;
};

#endif /* defined(__Reflex__World__) */
