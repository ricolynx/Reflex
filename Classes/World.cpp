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
    
    scene = s;
    
    this->moveSys = new MoveSystem();
    
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    //initialise batchnode and sharesprite
    batchNode = cocos2d::CCSpriteBatchNode::create("Sprites.pvr.ccz");
    
    scene->addChild(batchNode);
    
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("Sprites.plist");
    
    //-> create the canon
    canon = new Entity(this->nextEntityId ++, Entity::canon, "SpaceFlier_sm_1.png");
    canon->setPos(worldSize.width * 0.5, worldSize.height * 0.5);
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
    Entity* enemy = new Entity(this->nextEntityId++, Entity::enemy, "asteroid.png");
    cocos2d::CCPoint p = this->getRandomPoint();
    //std::cout << p.x << "-" << p.y << std::endl;
    
    enemy->setPos(p.x, p.y);
    
    enemy->addComponentToEntity(new component::TargetComponent(this->canon));
    //std::cout<< enemy->getComponent<component::TargetComponent>()->getTarget()->getId() <<std::endl;
    
    enemy->addComponentToEntity(new component::VelocityComponent());
    //std::cout<< enemy->getComponent<component::VelocityComponent>()->speedX <<std::endl;
    
    this->enemies.push_back(*enemy);
    this->moveSys->addEntity(enemy);
    this->scene->addChild(enemy->sprite);
}

//get a random point in the world
cocos2d::CCPoint World::getRandomPoint()
{
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    std::uniform_int_distribution<unsigned> u1(0,(int)worldSize.width);
    std::uniform_int_distribution<unsigned> u2(0,(int)worldSize.height);
    
    std::default_random_engine e;
    e.seed(time(0));
    
    return ccp(u1(e),u2(e));
    
}

//update function of the world
void World::update(float dt)
{
    
}
