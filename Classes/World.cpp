//
//  World.cpp
//  Reflex
//
//  Created by Eric Giraud on 06/11/2013.
//
//


#include "World.h"
#include "PopupLayer.h"
#include "GameScene.h"

World::World(cocos2d::CCLayer* s)
{
    showLogs = false;
    
    if (showLogs)
        std::cout<< "World constructor"<<std::endl;
    
    this->showCollisionZones = false;
    
    this->pause = false;
    
    this->nextEntityId = 0;
    
    this->count = 0;
    
    this->canonAngle = 0;
    
    this->rotateCanon = 0;
    
    this->life = 3;
    
    //init the seed of the 
    this->randomEngine.seed(time(0));
    
    this->scene = s;
    
    this->worldSize = cocos2d::CCDirector::sharedDirector()->getWinSize();
    
    this->moveSys = new MoveSystem(this->worldSize.width, this->worldSize.height);
    
    this->collisionSys = new CollisionSystem();
    
    //initialise batchnode and sharesprite
    batchNode = cocos2d::CCSpriteBatchNode::create("gameAtlas.png");
    
    scene->addChild(batchNode);
    
    cocos2d::CCSpriteFrameCache::sharedSpriteFrameCache()->addSpriteFramesWithFile("gameAtlas.plist");
    
    //create the canon
    canon = std::shared_ptr<Entity>(new Entity(this->nextEntityId ++, Entity::canon, "canon.png",40));
    
    canon->setPos(this->worldSize.width * 0.5, this->worldSize.height * 0.5);
    
    canon->addComponentToEntity(new component::LifeComponent(this->life));
    canon->addComponentToEntity(new component::AmmoComponent(3,3));
    
    this->scene->addChild(canon->sprite);
    
    this->collisionSys->addEntity(canon);
    
    if (this->showCollisionZones)
        canon->showCollisionZones(true);
}

World::~World()
{
    if (showLogs)
        std::cout<< "World destructor"<<std::endl;
    
    this->canon = 0;
    
    delete moveSys;
    
    delete collisionSys;
    
    this->enemies.clear();
    
    this->enemies.clear();
    
    this->bonuses.clear();
    
    this->batchNode = 0;
    
    this->scene = 0;

}

//reset the game
void World::resetGame()
{
    //pause game
    this->pause = true;
    
    //reset game variables
    this->count = 0;
    this->rotateCanon = 0;
    this->canonAngle = 0;
    
    //reset canon position
    this->canon->setRotation(0);
    
    //reset number of lifes
    this->canon->getComponent<component::LifeComponent>()->life = 3;
    
    //clean bullets
    this->cleanBullets();
    
    //clean enemies
    this->cleanEnemies();
    
    //clean bonuses
    this->cleanBonuses();
    
    //unpause the game
    this->pause = false;
}


//get the number of lives
int World::getLives()
{
    return this->life;
}

//add an enemy in the world
void World::addEnemy()
{
    std::shared_ptr<Entity> enemy = std::shared_ptr<Entity>(new Entity(this->nextEntityId++, Entity::enemy, "enemi1.png", 43));
    cocos2d::CCPoint p = this->getRandomPoint();
    
    enemy->setPos(p.x, p.y);
    
    enemy->addComponentToEntity(new component::TargetComponent(this->canon));
    
    enemy->addComponentToEntity(new component::VelocityComponent());
    
    enemy->addComponentToEntity(new component::LifeComponent(1));
    
    enemy->addComponentToEntity(new component::BonusComponent(component::BonusComponent::ammo));
    
    this->setInitialVelocity(enemy, 50);
    
    this->enemies.push_back(enemy);
    this->moveSys->addEntity(enemy);
    this->collisionSys->addEntity(enemy);
    this->scene->addChild(enemy->sprite);
    if (this->showCollisionZones)
        enemy->showCollisionZones(true);
}

void World::fireSingleBullet(std::shared_ptr<Entity> from, int angle, float speed)
{
    std::shared_ptr<Entity> bullet = std::shared_ptr<Entity>(new Entity(this->nextEntityId++, Entity::bullet, "bullet.png",5));
    
    bullet->setPos(from->posX(), from->posY());
    
    bullet->setRotation(angle);

    this->scene->addChild(bullet->sprite,-1);
    
    bullet->addComponentToEntity(new component::VelocityComponent);
    
    bullet->addComponentToEntity(new component::LifeComponent(1));
    
    this->setInitialBulletVelocity(bullet, angle, speed);
    
    this->bullets.push_back(bullet);
    
    this->moveSys->addEntity(bullet);
    this->collisionSys->addEntity(bullet);

    if (this->showCollisionZones)
        bullet->showCollisionZones(true);
}

//fire 4 bullets at same time
void World::fireBullets(std::shared_ptr<Entity> from, int nbBullets, float speed){
    
    float angleDelta = 360 / nbBullets;
    
    for (int i = 0 ; i< nbBullets ; i++)
    {
        this->fireSingleBullet(this->canon, this->canon->angle() + i * angleDelta, 500);
    }
}

//add a bonus from an entity (when it's destroyed)
void World::addBonusFromEntity(component::BonusComponent::BONUS_TYPE bonusType, std::shared_ptr<Entity> fromEntity)
{
    const char *imgName;
    switch (bonusType) {
        case component::BonusComponent::ammo :
            imgName = "bonus_amo.png";
            break;
            
        default:
            break;
    }
    
    std::shared_ptr<Entity> bonus = std::shared_ptr<Entity>(new Entity(this->nextEntityId++, Entity::bonus, imgName,20));
    bonus->addComponentToEntity(new component::VelocityComponent);
    bonus->addComponentToEntity(new component::LifeComponent(1));
    bonus->addComponentToEntity(new component::BonusComponent(bonusType));
    
    bonus->setPos(fromEntity->posX(), fromEntity->posY());
    
    this->setInitialVelocity(bonus, 50);
    
    this->scene->addChild(bonus->sprite);
    
    this->bonuses.push_back(bonus);
    
    this->moveSys->addEntity(bonus);
    
    this->collisionSys->addEntity(bonus);
    
    if (this->showCollisionZones)
        bonus->showCollisionZones(true);
}


//get a random point in the world
cocos2d::CCPoint World::getRandomPoint()
{
    
    std::uniform_int_distribution<unsigned> u(0,3);
    int a, b, c, d;
    
    switch(u(randomEngine))
    {
        case 0:
            a = - 200;
            b = - 100;
            c = - 50;
            d = (int)this->worldSize.height + 50;
            break;
        case 1:
            a = - 50;
            b = (int)this->worldSize.width + 50;
            c = - 200;
            d = - 100;
            break;
        case 2:
            a = - 50;
            b = (int)this->worldSize.width + 50;
            c = (int)this->worldSize.height + 100;
            d = (int)this->worldSize.height + 200;
            break;
        default:
            a = (int)this->worldSize.width + 100;
            b = (int)this->worldSize.width + 200;
            c = - 50;
            d = (int)this->worldSize.height + 50;
            break;
    }
    std::uniform_int_distribution<int> u1(a,b);
    std::uniform_int_distribution<int> u2(c,d);
    cocos2d::CCPoint p = ccp(u1(randomEngine) , u2(randomEngine));
    return p;
    
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
            targetX = this->worldSize.width / 2;
            targetY = this->worldSize.height / 2;
        }
        
        float distX =  targetX - entity->posX()  ;
        float distY =  targetY - entity->posY()  ;
        float dist = sqrt(pow(distX,2) + pow(distY,2));
        
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

//remove bullets that are "dead"
void World::removeDeadBullets()
{
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->bullets.begin();it != this->bullets.end(); it++)
    {
        std::shared_ptr<Entity> entity = *it;
        //std::cout<< &entity << std::endl;
        component::LifeComponent* lc = entity->getComponent<component::LifeComponent>();
        //std::cout<< lc << std::endl;
        if (!lc || lc->life < 1 )
        {
            if (showCollisionZones)
                entity->showCollisionZones(false);
            this->scene->removeChild(entity->sprite,true);
            this->moveSys->removeEntity(entity);
            this->collisionSys->removeEntity(entity);
            this->bullets.remove(entity);
            //we remove only one bullet per frame to avoid conflict in list iteration
            break;
        }
    }
}

//remove bullets that are "dead"
void World::removeDeadEnemies()
{
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->enemies.begin();it != this->enemies.end(); it++)
    {
        std::shared_ptr<Entity> entity = *it;

        component::LifeComponent* lc = entity->getComponent<component::LifeComponent>();

        if (!lc || lc->life < 1 )
        {
            //if there is a bonus --> addbonus
            component::BonusComponent *bc =entity->getComponent<component::BonusComponent>();
            if (bc!=0)
                this->addBonusFromEntity(bc->getType(), entity);
            
            if (showCollisionZones)
                entity->showCollisionZones(false);
            this->scene->removeChild(entity->sprite);
            this->moveSys->removeEntity(entity);
            this->collisionSys->removeEntity(entity);
            this->enemies.remove(entity);
            //we remove only one enemiy per frame to avoid conflict in list iteration
            break;
        }
    }
}

//remove bonuses that are "dead"
void World::removeDeadBonuses()
{
    for (std::list<std::shared_ptr<Entity>>::iterator it = this->bonuses.begin();it != this->bonuses.end(); it++)
    {
        std::shared_ptr<Entity> entity = *it;
        
        component::LifeComponent* lc = entity->getComponent<component::LifeComponent>();
        
        if (!lc || lc->life < 1 )
        {
            if (showCollisionZones)
                entity->showCollisionZones(false);
            this->scene->removeChild(entity->sprite);
            this->moveSys->removeEntity(entity);
            this->collisionSys->removeEntity(entity);
            this->bonuses.remove(entity);
            //we remove only one bonus per frame to avoid conflict in list iteration
            break;
        }
    }
}

// clean all bullets
void World::cleanBullets()
{
    std::shared_ptr<Entity> entity;
    while (this->bullets.size() > 0)
    {
        entity = this->bullets.back();
        if (showCollisionZones)
            entity->showCollisionZones(false);
        this->scene->removeChild(entity->sprite);
        this->moveSys->removeEntity(entity);
        this->collisionSys->removeEntity(entity);
        this->bullets.pop_back();
        entity = 0;
    }
    this->bullets.clear();
}

//clean all enemies
void World::cleanEnemies()
{
    std::shared_ptr<Entity> entity;
    while (this->enemies.size() > 0)
    {
        entity = this->enemies.back();
        if (showCollisionZones)
            entity->showCollisionZones(false);
        this->scene->removeChild(entity->sprite);
        this->moveSys->removeEntity(entity);
        this->collisionSys->removeEntity(entity);
        this->enemies.pop_back();
        entity = 0;
    }
    this->enemies.clear();
}

//clean the bonuses
void World::cleanBonuses()
{
    std::shared_ptr<Entity> entity;
    while (this->bonuses.size() > 0)
    {
        entity = this->bonuses.back();
        if (showCollisionZones)
            entity->showCollisionZones(false);
        this->scene->removeChild(entity->sprite);
        this->moveSys->removeEntity(entity);
        this->collisionSys->removeEntity(entity);
        this->bonuses.pop_back();
        entity = 0;
    }
    this->bonuses.clear();
}

//pause the game
void World::pauseGame()
{
    this->rotateCanon = 0;
    this->pause = !this->pause;
    
    if (this->pause && dynamic_cast<GameScene*>(this->scene)->popupLayer!=0)
    {
        SimpleDelegate<World> *delegate = new SimpleDelegate<World>(this, &World::pauseGame);
        dynamic_cast<GameScene*>(this->scene)->popupLayer->test(dynamic_cast<Delegate*>(delegate));
    }
    
}

//return if the game is paused or not
bool World::isPaused()
{
    return this->pause;
}

//update function of the world
void World::update(float dt)
{
    if (this->pause)
        return;

    count = (count + 1 ) % 60;

    if (count == 1)
        this->addEnemy();
    
    if (this->rotateCanon!=0)
    {
        this->canonAngle = (this->canonAngle + this->rotateCanon) % 360;
        this->canon->setRotation(this->canonAngle);
    }
    
    this->moveSys->update(dt);
    this->collisionSys->update(dt);
    this->removeDeadBullets();
    this->removeDeadEnemies();
    this->removeDeadBonuses();
    
    int nbLife = this->canon->getComponent<component::LifeComponent>()->life;
    if (this->life != nbLife)
    {
        std::cout << "update life" << std::endl;
        this->life = nbLife;
    }
}

//when touch starts
void World::onTouchesBegan(cocos2d::CCSet* touches)
{
    if (this->pause)
        return;
    
    cocos2d::CCTouch *touch = (cocos2d::CCTouch*) (touches->anyObject());
    if (touch->getLocationInView().x > this->worldSize.width /2)
        this->rotateCanon = -1;
    else
        this->rotateCanon = 1;
}

//when touch stops
void World::onTouchesEnded(cocos2d::CCSet* touches)
{
    if (this->pause)
        return;
    this->rotateCanon = 0;
    
    if (this->canon->getComponent<component::AmmoComponent>()->getAmmo()>0)
    {
        this->fireBullets(this->canon, 4 , 500);
        this->canon->getComponent<component::AmmoComponent>()->shoot();
    }
}




