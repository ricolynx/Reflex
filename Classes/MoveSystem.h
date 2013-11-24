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
#include <memory>
#include "Entity.h"


class MoveSystem
{
private:
    
    bool showLogs;
    
    //reference to the related entity
    std::list<std::shared_ptr<Entity>> movingEntities;
    
    void move(std::shared_ptr<Entity> entity, float dt);
    
    int worldWidth ;
    int worldHeight ;
    
    
public:
    //Constructor
    MoveSystem(float ww, float wh);
    
    //destructor
    ~MoveSystem();
    
    void addEntity(std::shared_ptr<Entity> entity);
    
    void removeEntity(std::shared_ptr<Entity> entity);
    
    void update(float dt);
};


#endif /* defined(__Reflex__MoveSystem__) */
