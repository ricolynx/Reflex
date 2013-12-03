//
//  Entity.cpp
//  Reflex
//
//  Created by Eric Giraud on 04/11/2013.
//
//

#include "Entity.h"

//Constructor
Entity::Entity(int newId, ENTITY_TYPE newType, const char* imageName, float r)
{
    showLogs = true;
    
    
    if (showLogs)
        std::cout << "entity " << newId << "-" << newType << "- constructor - " << std::endl;
    
    this->Id = newId;
    
    this->type = newType;
    
    this->_angle = 0;
    
    this->_size = r;
    
    this->sprite = cocos2d::CCSprite::createWithSpriteFrameName(imageName);
    
    this->collisionZone = 0;
}


Entity::~Entity()
{
    if (showLogs)
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


void Entity::showCollisionZones(bool showZone){
    if (showZone)
    {
        if (this->collisionZone == 0)
        {
            this->collisionZone = new BoundingSprite(this->size(),this->sprite->getContentSize().width /2,this->sprite->getContentSize().height /2);
            this->sprite->addChild(this->collisionZone);
        }
    }
    else
    {
        //std::cout << false << std::endl;
        if (this->collisionZone != 0)
        {
            this->sprite->removeChild(this->collisionZone,true);
            delete this->collisionZone;
            this->collisionZone = 0;
        }
    }
}


// add a component
void Entity::addComponentToEntity(component::Component* component)
{
    //this->components[&typeid(*component)] = component;
    this->components[std::type_index(typeid(*component))] = component;
}





