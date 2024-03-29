//
//  CollisionSystem.cpp
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#include "CollisionSystem.h"
#include "LifeComponent.h"
#include "AmmoComponent.h"
#include "BonusComponent.h"
#include "ShieldComponent.h"
#include "ShotGroupComponent.h"
#include "ScoreController.h"
#include "ScoreAction.h"

CollisionSystem::CollisionSystem()
{
    showLogs = false;
    
    if (showLogs)
        std::cout << "CollisionSystem - constructor - " << std::endl;

}

CollisionSystem::~CollisionSystem()
{
    if (showLogs)
        std::cout << "CollisionSystem - destructor - " << std::endl;

}

//add an entity in the collision system
void CollisionSystem::addEntity(std::shared_ptr<Entity> entity)
{
    switch (entity->getType()) {

        case Entity::bullet:
            this->bullets.push_back(entity);
            break;
            
        case Entity::bonus:
        case Entity::enemy:
            this->movingEntities.push_back(entity);
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
    if (entity==0)
        return;
    
    switch (entity->getType()) {
            
        case Entity::bullet:
            this->bullets.remove(entity);
            break;
            
        case Entity::bonus:
        case Entity::enemy:
            this->movingEntities.remove(entity);
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
    //collisions with enemy
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->movingEntities.begin();it != this->movingEntities.end(); it++)
    {
        std::shared_ptr<Entity> entity = *it;
        if (entity->getComponent<component::LifeComponent>()->life< 1)
            continue;
        for (std::list<std::shared_ptr<Entity>>::iterator itb = this->bullets.begin();itb != this->bullets.end(); itb++)
        {
            std::shared_ptr<Entity> bullet = *itb;
            if (bullet->getComponent<component::LifeComponent>()->life<1)
                continue;
            if (this->checkCollision(bullet,entity))
            {
                --(*entity->getComponent<component::LifeComponent>());
                entity->sprite->setOpacity(255.0f * ((float)entity->getComponent<component::LifeComponent>()->life / (float)entity->getComponent<component::LifeComponent>()->getMaxLife()));
                --(*bullet->getComponent<component::LifeComponent>());
                
                if (entity->getComponent<component::LifeComponent>()->life == 0)
                {
                    if (entity->getType() == Entity::enemy)
                        ScoreController::Instance()->addAction( ScoreAction( ScoreAction::destroyPlanet, bullet->getComponent<component::ShotGroupComponent>()->groupId));
                    else
                        ScoreController::Instance()->addAction( ScoreAction( ScoreAction::shootBonus, bullet->getComponent<component::ShotGroupComponent>()->groupId));
                }
                else
                    ScoreController::Instance()->addAction( ScoreAction( ScoreAction::shootPlanet, bullet->getComponent<component::ShotGroupComponent>()->groupId));
                continue;
            }
        }
        if (this->checkCollision(entity, this->canon))
        {
            entity->getComponent<component::LifeComponent>()->life = 0;
            if (this->canon->getComponent<component::LifeComponent>()->life >0)
            {
                if (entity->getType() == Entity::enemy)
                {
                    entity->removeComponent<component::BonusComponent>();
                    ScoreController::Instance()->addAction( ScoreAction( ScoreAction::destroyPlanet ));
                    if (this->canon->getComponent<component::ShieldComponent>() == NULL)
                    {
                        --(*this->canon->getComponent<component::LifeComponent>());
                        this->canon->getComponent<component::AmmoComponent>()->recharge();
                    }
                }
                else if (entity->getType() == Entity::bonus)
                {
                    ScoreController::Instance()->addAction( ScoreAction( ScoreAction::getBonus ));
                    switch(entity->getComponent<component::BonusComponent>()->getType())
                    {
                        case component::BonusComponent::ammo:
                            this->canon->getComponent<component::AmmoComponent>()->recharge();
                            break;
                        case component::BonusComponent::life:
                            ++(*this->canon->getComponent<component::LifeComponent>());
                            break;
                    }
                }
            }
            continue;
        }
    }
    
}

