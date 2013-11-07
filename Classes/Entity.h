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
    
    //enums the different types of entities
    enum ENTITY_TYPE {
        spaceship,
        asteroid,
        bullet
    };
    
    
private :
    
    //Id of the entity
    int Id;
    
    //position x
    int x;
    
    //position y
    int y;
    
    //size if the entity (ray)
    int size;
    
    //velocity if the entity (in x and y)
    cocos2d::CCPoint* velocity;
    
    //angle of the entity
    int angle; // int ?
    
    //type of the entity
    ENTITY_TYPE type;
    
    //specific properties of an entity
    // properties;
    
public :
    
    Entity(int newId, ENTITY_TYPE newType);
    ~Entity();
    
    //initialise the entity
    bool init();
    
    //update the entity
    void update();
    
    //set the position of the entity
    void setPos(int,int);
    
    //set the angle of the entity
    void setAngle(int);
    
    //get the id of the entity
    int getId();
};


#endif /* defined(__Reflex__Entity__) */
