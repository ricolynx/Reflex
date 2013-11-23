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
    
    bool checkCollision(std::shared_ptr<Entity> entity1, std::shared_ptr<Entity> entity2)
    {
        float distX =  entity1->posX() - entity2->posX()  ;
        float distY =  entity1->posY() - entity2->posY()  ;
        float dist = sqrt(pow(distX,2) + pow(distY,2));
        return dist < entity1->size() + entity2->size();
    }
    
    void update(float dt);
    
};

#endif /* defined(__Reflex__CollisionSystem__) */
