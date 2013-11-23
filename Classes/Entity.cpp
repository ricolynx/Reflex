//
//  Entity.cpp
//  Reflex
//
//  Created by Eric Giraud on 04/11/2013.
//
//

#include "Entity.h"


//Constructor
Entity::Entity(int newId, ENTITY_TYPE newType, const char* imageName)
{
    std::cout << "entity " << newId << "-" << newType << "- constructor - " << std::endl;
    
    this->Id = newId;
    
    this->type = newType;
    
    this->_angle = 0;
    
    this->sprite = cocos2d::CCSprite::createWithSpriteFrameName(imageName);
}


Entity::~Entity()
{
    std::cout << "entity " << this->Id << "-" << this->type << "- destructor -" << std::endl;
    
    this->sprite = 0;
    
    for (auto it  = this->components.begin(); it != this->components.end() ; it++)
    {
        delete it->second;
    }
    
    this->components.clear();
}

//get the id of the entity
int Entity::getId()
{
    return this->Id;
}

//set the position of the entity (and its sprite)
void Entity::setPos(float x, float y)
{
    //std::cout<<x <<" "<<y<< std::endl;
    
    this->_posX = x;
    this->_posY = y;
    
    this->sprite->setPosition(ccp(x,y));
}


void Entity::setRotation(int a)
{
    this->_angle = a % 360;
    this->sprite->setRotation(this->_angle);
}

// add a component
void Entity::addComponentToEntity(component::Component* component)
{
    //this->components[&typeid(*component)] = component;
    this->components[std::type_index(typeid(*component))] = component;
}

//get a component
template <typename T>
T* Entity::getComponent(){
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

//explicits instantiations of get component
template component::VelocityComponent* Entity::getComponent<component::VelocityComponent>();
template component::TargetComponent* Entity::getComponent<component::TargetComponent>();
template component::LifeComponent* Entity::getComponent<component::LifeComponent>();




