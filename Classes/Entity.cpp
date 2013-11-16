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
    
    this->sprite = cocos2d::CCSprite::createWithSpriteFrameName(imageName);
}


Entity::~Entity()
{
    std::cout << "entity " << this->Id << "-" << this->type << "- destructor -" << std::endl;
    
    //delete this->sprite;
}

//get the id of the entity
int Entity::getId()
{
    return this->Id;
}

//set the position of the entity (and its sprite)
void Entity::setPos(int x, int y)
{
    this->posX = x;
    this->posY = y;
    
    this->sprite->setPosition(ccp(x,y));
}


// add a component
void Entity::addComponentToEntity(component::Component * component)
{
    this->components[&typeid(*component)] = component;
}

//get a component
template <typename T>
T* Entity::getComponent(){
    if(components.count(&typeid(T)) != 0)
    {
        return static_cast<T*>(components[&typeid(T)]);
    }
    else
    {
        return 0;
    }
}

//explicits instantiations of get component
template component::VelocityComponent* Entity::getComponent<component::VelocityComponent>();
template component::TargetComponent* Entity::getComponent<component::TargetComponent>();




