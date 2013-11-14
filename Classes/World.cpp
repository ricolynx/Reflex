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
    
    this->enemies.clear();
    
    this->bullets.clear();
}

//add an enemy in the world
void World::addEnemy()
{
    Entity* enemy = new Entity(this->nextEntityId++, Entity::enemy, "asteroid.png");
    cocos2d::CCPoint p = this->getRandomPoint();
    std::cout << p.x << "-" << p.y << std::endl;
    
    enemy->setPos(p.x, p.y);
    this->enemies.push_back(*enemy);
    this->scene->addChild(enemy->sprite);
}

//get a random point in the world
cocos2d::CCPoint World::getRandomPoint()
{
    cocos2d::CCSize worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    srand(time(NULL));
    return ccp(rand() % (int) worldSize.width + 1, rand() % (int) worldSize.height);
}

//update function of the world
void World::update(float dt)
{
    
}
