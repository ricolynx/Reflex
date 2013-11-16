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
#include <unordered_map>

#include "component.h"
#include "VelocityComponent.h"
#include "TargetComponent.h"

#include "cocos2d.h"



class Entity
{
public:
    
    //enums the different types of entities
    enum ENTITY_TYPE {
        canon,
        enemy,
        bullet
    };
    
private :
    
    //Id of the entity
    int Id;
    
    //position x of the entity
    int posX;
    
    //position y of the entity
    int posY;
    
    //size if the entity (ray)
    int size;
    
    //type of the entity
    ENTITY_TYPE type;

    //components of the entity
    std::unordered_map<const std::type_info*, component::Component*> components;
    

    
public :
    
    //sprite of the entity
    cocos2d::CCSprite* sprite;
    
    //constructor
    Entity(int newId, ENTITY_TYPE newType, const char* imageName);
    
    //destructor
    ~Entity();
    
    //initialise the entity
    bool init();
    
    //update the entity
    void update();
    
    //set the position of the entity
    void setPos(int,int);
    
    //set the velocity of the entity
    void setVelocity(int velX, int velY);
    
    //set the initial velocity of the entity
    void setInitialVelocity(int coef);
    
    //set the target 
    void setTarget(Entity *entity);
    
    //get the id of the entity
    int getId();
    
    // add a component
    void addComponentToEntity(component::Component *component);
    
    //template function to get a component
    template <typename T>
    T* getComponent();
    
    //operator override
    bool operator ==(Entity ent)
    {
        return ent.getId() == this->Id;
    }
};


#endif /* defined(__Reflex__Entity__) */
