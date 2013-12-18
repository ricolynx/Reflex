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
    this->_currentScore ++;
    std::cout<< "new score : " << this->_currentScore << std::endl;
    
    //notify observers
    this->notify(scoreAction);
    
    return this->_currentScore;
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


