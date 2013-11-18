//
//  CollisionSystem.h
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#ifndef __Reflex__CollisionSystem__
#define __Reflex__CollisionSystem__

#include <iostream>
#include <memory>
#include <list>

#include "Entity.h"

class CollisionSystem{
    
    private :
    
    std::list<std::shared_ptr<Entity>> enemies;
    
    std::list<std::shared_ptr<Entity>> bullets;
    
    std::shared_ptr<Entity> canon;
    
    
    public:
    
    CollisionSystem();
    
    ~CollisionSystem();
    
    void addEntity(std::shared_ptr<Entity> entity);
    
    void removeEntity(std::shared_ptr<Entity> entity);
    
    void update(float dt);
    
};

#endif /* defined(__Reflex__CollisionSystem__) */
