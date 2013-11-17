//
//  World.cpp
//  Reflex
//
//  Created by Eric Giraud on 06/11/2013.
//
//


#include "World.h"


World::World(cocos2d::CCLayer* s)
{
    std::cout<< "World constructor"<<std::endl;
    
    //init the seed of the 
    this->randomEngine.seed(time(0));
    
    scene = s;
    
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    this->moveSys = new MoveSystem(worldSize.width, worldSize.height);
    
    
    //initialise batchnode and sharesprite
    batchNode = cocos2d::CCSpriteBatchNode::create("Sprites.pvr.ccz");
    
    scene->addChild(batchNode);
    
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Sprites.plist");
    
    //create the canon
    canon = new Entity(this->nextEntityId ++, Entity::canon, "SpaceFlier_sm_1.png");
    
    canon->setPos(worldSize.width * 0.5, worldSize.height * 0.5);
    
    canon->addComponentToEntity(new component::LifeComponent(1));
    
    this->scene->addChild(canon->sprite);
}

World::~World()
{
    std::cout<< "World destructor"<<std::endl;
    
    delete this->canon;
    
    delete moveSys;
    
    this->enemies.clear();
    
    this->bullets.clear();
}

//add an enemy in the world
void World::addEnemy()
{
    std::shared_ptr<Entity> enemy = std::shared_ptr<Entity>(new Entity(this->nextEntityId++, Entity::enemy, "asteroid.png"));
    cocos2d::CCPoint p = this->getRandomPoint();
    //std::cout << p.x << "-" << p.y << std::endl;
    
    enemy->setPos(p.x, p.y);
    
    enemy->addComponentToEntity(new component::TargetComponent(this->canon));
    
    enemy->addComponentToEntity(new component::VelocityComponent());
    
    enemy->addComponentToEntity(new component::LifeComponent(1));
    
    this->setInitialVelocity(enemy, 50);
    
    this->enemies.push_back(enemy);
    this->moveSys->addEntity(enemy);
    this->scene->addChild(enemy->sprite);
}

void World::fireSingleBullet(Entity* from, int angle, float speed)
{
    std::shared_ptr<Entity> bullet = std::shared_ptr<Entity>(new Entity(this->nextEntityId++, Entity::bullet, "laserbeam_blue.png"));
    
    bullet->setPos(from->posX(), from->posY());
    
    bullet->setRotation(angle);

    this->scene->addChild(bullet->sprite,-1);
    
    bullet->addComponentToEntity(new component::VelocityComponent);
    
    bullet->addComponentToEntity(new component::LifeComponent(1));
    
    this->setInitialBulletVelocity(bullet, angle, speed);
    
    this->bullets.push_back(bullet);
    
    this->moveSys->addEntity(bullet);

}


//get a random point in the world
cocos2d::CCPoint World::getRandomPoint()
{
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    std::uniform_int_distribution<unsigned> u1(0,(int)worldSize.width);
    std::uniform_int_distribution<unsigned> u2(0,(int)worldSize.height);
    
    return ccp(u1(randomEngine),u2(randomEngine));
    
}

//set the initial velocity of an entity (calculated with the target. If no target it goes to 0 point)
void World::setInitialVelocity(std::shared_ptr<Entity> entity, int coef)
{
    component::VelocityComponent *vc = entity->getComponent<component::VelocityComponent>();
    if (vc)
    {
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
        std::cout << entity->posX() <<" " << entity->posY()<< std::endl;
        std::cout << targetX <<" " << targetY<< std::endl;
        
        float distX =  targetX - entity->posX()  ;
        float distY =  targetY - entity->posY()  ;
        float dist = sqrt(pow(distX,2) + pow(distY,2));
        
        std::cout << (distX/dist) * coef << std::endl;
        std::cout << (distY/dist) * coef << std::endl;
        
        vc->speedX = (distX/dist) * coef;
        vc->speedY = (distY/dist) * coef;
    }
}

//set the initial velocity of a bullet
void World::setInitialBulletVelocity(std::shared_ptr<Entity> bullet, float angle, float speed)
{
    component::VelocityComponent *vc = bullet->getComponent<component::VelocityComponent>();
    if (vc)
    {
        angle = angle * 3.14159265 / 180;
        vc->speedX = cosf(angle)* speed;
        vc->speedY = - sinf(angle)* speed;
    }
}

void World::removeDeadBullets()
{
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->bullets.begin();it != this->bullets.end(); it++)
    {
        std::shared_ptr<Entity> entity = *it;
        //std::cout<< &entity << std::endl;
        component::LifeComponent* lc = entity->getComponent<component::LifeComponent>();
        //std::cout<< lc << std::endl;
        if (!lc || lc->life < 1)
        {
            this->scene->removeChild(entity->sprite);
            this->moveSys->removeEntity(entity);
            this->bullets.remove(entity);
            //we remove only one bullet per frame to avoid conflict in list iteration
            break;
        }
    }
}



//update function of the world
void World::update(float dt)
{
    count = (count + 1 ) % 360;
    this->canon->setRotation(count);
    this->moveSys->update(dt);
    this->removeDeadBullets();
}
