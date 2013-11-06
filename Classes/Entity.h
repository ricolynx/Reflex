//
//  Entity.h
//  Reflex
//
//  Created by Eric Giraud on 04/11/2013.
//
//

#ifndef __Reflex__Entity__
#define __Reflex__Entity__

#include <iostream>
#include "cocos2d.h"

class Entity
{
    
public:
    enum entity_type {
        spaceship,
        asteroid,
        bullet
    };
    
private :
    
    int id;
    
    int x;
    
    int y;
    
    int size;
    
    cocos2d::CCPoint* velocity;
    
    int angle; // int ?
    
    entity_type type;
    
    char* properties;//-> may be a dictionary (map)
    
public :
    
    Entity();
    ~Entity();
    
    void setPos(int,int);

};


#endif /* defined(__Reflex__Entity__) */
