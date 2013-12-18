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
    
    return this->_currentScore;
}