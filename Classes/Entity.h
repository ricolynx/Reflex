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
    
    enum ENTITY_TYPE {
        spaceship,
        asteroid,
        bullet
    };
    
    
private :
    
    int Id;
    
    int x;
    
    int y;
    
    int size;
    
    cocos2d::CCPoint* velocity;
    
    int angle; // int ?
    
    ENTITY_TYPE type;
    
    char* properties;//-> may be a dictionary (map)
    
public :
    
    Entity(int newId, ENTITY_TYPE newType);
    ~Entity();
    
    bool init();
    
    void update();
    
    void setPos(int,int);
    
    void setAngle(int);
    
    int getId();
};


#endif /* defined(__Reflex__Entity__) */
