//
//  MoveSystem.cpp
//  Reflex
//
//  Created by Eric Giraud on 13/11/2013.
//
//

#include "MoveSystem.h"

MoveSystem::MoveSystem(float ww,float wh)
{
    std::cout << "MoveSystem - constructor - " << std::endl;
    this->worldWidth = ww;
    this->worldHeight = wh;
}


MoveSystem::~MoveSystem()
{
    std::cout << "MoveSystem - destructor - " << std::endl;
    //this->movingEntities.clear();
}


void MoveSystem::addEntity(std::shared_ptr<Entity> entity)
{
    this->movingEntities.push_back(entity);
}

void MoveSystem::removeEntity(std::shared_ptr<Entity> entity)
{
    this->movingEntities.remove(entity);
}

void MoveSystem::move(std::shared_ptr<Entity> entity, float dt)
{
    component::VelocityComponent *vc = entity->getComponent<component::VelocityComponent>();
    if (!vc->isMoving)
        return;
    if (vc)
    {
        //update the position
        entity->setPos(entity->posX() + dt * (vc->speedX), entity->posY() + dt * (vc->speedY));
        float targetX, targetY;
        component::TargetComponent *tc = entity->getComponent<component::TargetComponent>();
        if (tc != 0)
        {
            targetX = tc->getTarget()->posX();
            targetY = tc->getTarget()->posY();
        }
        else
        {
            cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
            targetX = worldSize.width / 2;
            targetY = worldSize.height / 2;
        }
        
        if (entity->posX() < - 210 || entity->posY() < - 210 || entity->posX() > this->worldWidth + 210 || entity->posY() > this->worldHeight + 210)
        {
            component::LifeComponent *lc = entity->getComponent<component::LifeComponent>();
            if (lc){
                lc->life--;
                std::cout<<"remove life of entity "<<entity->getId() << std::endl;
            }
            
        }
        
        //if (abs(round(targetX) - round(entity->posX())) <= 3 && abs(round(targetY) - round(entity->posY())) <= 3)
            //vc->isMoving = false;
    }
}


void MoveSystem::update(float dt)
{
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->movingEntities.begin();it != this->movingEntities.end(); it++)
    {
        this->move(*it, dt);
    }
}

