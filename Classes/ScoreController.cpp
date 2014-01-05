//
//  ScoreController.cpp
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#include "ScoreController.h"
#include "ScoreAction.h"

//instance
ScoreController* ScoreController::_instance = NULL;

//constructor
ScoreController::ScoreController()
{
    this->bulletCounters = std::vector<int> (100,0);
    this->scoreCounter = std::vector<int> (100,0);
}

//destructor
ScoreController::~ScoreController()
{
    
}

//get singleton instance
ScoreController* ScoreController::Instance()
{
    if (!_instance)
    {
        _instance = new ScoreController;
    }
    
    return _instance;
}

//get the current score
long ScoreController::currentScore()
{
    return this->_currentScore;
}

//reset the score
void ScoreController::resetScore()
{
    this->_currentScore = 0;
}

//add an action to the score
long ScoreController::addAction(ScoreAction scoreAction)
{
    /*
    std::string t;
    
    if (scoreAction.type == ScoreAction::destroyPlanet)
        t = "destroy planet";
    if (scoreAction.type == ScoreAction::getBonus)
        t = "get Bonus";
    if (scoreAction.type == ScoreAction::shootBonus)
        t = "shoot Bonus";
    if (scoreAction.type == ScoreAction::shootPlanet)
        t = "shoot Planet";
    
    std::cout<< "currscore :" << this->_currentScore << " - type (base score) : " << t <<" "<<scoreAction.type<< " - shootId : " << scoreAction.shootId << std::endl;
    */
    
    //-> calculate the score of the action
    if (scoreAction.shootId != -1)
    {
        ++(this->scoreCounter[scoreAction.shootId]);
        scoreAction.score = scoreAction.type * this->scoreCounter[scoreAction.shootId];
    }
    else
        scoreAction.score = scoreAction.type;
    
    //->update the currentScore
    this->_currentScore += scoreAction.score;
    
    //std::cout<< "new score : " << this->_currentScore <<" (+" << scoreAction.score << ")" << std::endl;
    
    //notify observers
    this->notify(scoreAction);
    
    //return the score
    return this->_currentScore;
}

// add a count to the bullet counters. This is called every time a bullet is destroyed and allow to add bonus on multiple shots
void ScoreController::addBulletCount(int salveId)
{
    ++(this->bulletCounters[salveId]);
    
    if (this->bulletCounters[salveId] == 4)
    {
        this->bulletCounters[salveId] = 0;
        this->scoreCounter[salveId] = 0;
    }
}


//attach an observer. Observers can be attached only once
void ScoreController::attach(ScoreObserver* scoreObs)
{
    //check if the observer is not already attached
    if (std::find(this->_observers.begin(),this->_observers.end(),scoreObs) ==this->_observers.end())
    {
        this->_observers.push_back(scoreObs);
    }
}

//detach an observer
void ScoreController::detach(ScoreObserver* scoreObs)
{
    for (auto it = this->_observers.begin() ; it!= this->_observers.end(); ++it)
    {
        if ((*it) == scoreObs)
        {
            this->_observers.erase(it);
            break;
        }
    }
}

//notify all observers of an aciton
void ScoreController::notify(ScoreAction action)
{
    for (auto it = this->_observers.begin() ; it!= this->_observers.end(); ++it)
    {
        (*it)->update(action, this->_currentScore);
    }
}


