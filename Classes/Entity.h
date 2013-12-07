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
#include <map>
#include <typeindex>
//#include <memory>

#include "component.h"
#include "BoundingSprite.h"

#include "cocos2d.h"

class Entity
{
public:
    
    //enums the different types of entities
    enum ENTITY_TYPE {
        canon,
        enemy,
        bullet,
        bonus
    };
    
private :
    
    bool showLogs;
    
    //Id of the entity
    int Id;
    
    //position x of the entity
    float _posX;
    
    //position y of the entity
    float _posY;
    
    int _angle ;
    
    //radius of the object
    float _size;
    
    //bool showCollisionZone
    
    
    //type of the entity
    ENTITY_TYPE type;

    //components of the entity
    std::map<std::type_index, component::Component*> components;
    
    //collisioonZone of the sprite
    cocos2d::CCSprite *collisionZone;
    
public :
    
    //sprite of the entity
    cocos2d::CCSprite *sprite;
    
    //size if the entity (radius)
    float size()
    {
        return _size;
    }
    
    //constructor
    Entity(int newId, ENTITY_TYPE newType, const char* imageName, float r);
    
    //destructor
    ~Entity();
    
    //initialise the entity
    bool init();
    
    //update the entity
    void update();
    
    //getter for posX
    float posX (){return _posX;};
    
    //getter for posY
    float posY (){return _posY;};
    
    //set the position of the entity
    void setPos(float x, float y);
    
    //get the angle
    int angle(){ return _angle;};

    //set the angle of the entity
    void setRotation(int a);
    
    //get the id of the entity
    int getId();
    
    //get the type of the entity
    ENTITY_TYPE getType(){return type;};
    
    // add a component
    void addComponentToEntity(component::Component* component);
    
    //template function to get a component
    template <typename T>
    T* getComponent(){
        std::type_index index(typeid(T));
        if(components.count(index) != 0)
        {
            return static_cast<T*>(components[index]);
        }
        else
        {
            return 0;
        }
    }
    
    //template to remove a component
    template <typename T>
    void removeComponent()
    {
        std::type_index index(typeid(T));
        if(components.count(index) != 0)
        {
            components.erase(index);
        }
    }
    
    //show or hide collision zone
    void showCollisionZones(bool showZone);
    
    //operator override
    bool operator ==(Entity ent)
    {
        return ent.getId() == this->Id;
    }
};


#endif /* defined(__Reflex__Entity__) */
