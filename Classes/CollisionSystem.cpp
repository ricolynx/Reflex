//
//  CollisionSystem.cpp
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#include "CollisionSystem.h"



CollisionSystem::CollisionSystem()
{
    std::cout << "CollisionSystem - constructor - " << std::endl;

}

CollisionSystem::~CollisionSystem()
{
    std::cout << "CollisionSystem - destructor - " << std::endl;

}

//add an entity in the collision system
void CollisionSystem::addEntity(std::shared_ptr<Entity> entity)
{
    switch (entity->getType()) {

        case Entity::bullet:
            bullets.push_back(entity);
            break;
        
        case Entity::enemy:
            enemies.push_back(entity);
            break;
            
        //default canon
        default:
            canon = entity;
            break;
    }
}

//remove an entity in the collision system
void CollisionSystem::removeEntity(std::shared_ptr<Entity> entity)
{
    switch (entity->getType()) {
            
        case Entity::bullet:
            this->bullets.remove(entity);
            break;
            
        case Entity::enemy:
            this->enemies.remove(entity);
            break;
            
            //default canon
        default:
            this->canon = 0;
            break;
    }
}


//update the collision system
void CollisionSystem::update(float dt)
{
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->enemies.begin();it != this->enemies.end(); it++)
    {
        std::shared_ptr<Entity> enemy = *it;
        if (enemy->getComponent<component::LifeComponent>()->life< 1)
            continue;
        for (std::list<std::shared_ptr<Entity>>::iterator itb = this->bullets.begin();itb != this->bullets.end(); itb++)
        {
            std::shared_ptr<Entity> bullet = *itb;
            if (bullet->getComponent<component::LifeComponent>()->life<1)
                continue;
            if (bullet->sprite->boundingBox().intersectsRect(enemy->sprite->boundingBox()))
            {
                enemy->getComponent<component::LifeComponent>()->life--;
                bullet->getComponent<component::LifeComponent>()->life--;
            }
        }
    }
}