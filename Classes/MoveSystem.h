//
//  MoveSystem.h
//  Reflex
//
//  Created by Eric Giraud on 13/11/2013.
//
//

#ifndef __Reflex__MoveSystem__
#define __Reflex__MoveSystem__

#include <iostream>
#include "Entity.h"

class MoveSystem
{
private:
    //reference to the related entity
    std::list<Entity> movingEntities;
    
public:
    //Constructor
    MoveSystem();
    
    //destructor
    ~MoveSystem();
    
    void addEntity(Entity* entity);
    
    void removeEntity(Entity* entity);
    
    void update(float dt);
};


#endif /* defined(__Reflex__MoveSystem__) */
