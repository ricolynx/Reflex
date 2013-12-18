//
//  ScoreController.cpp
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#include "ScoreController.h"

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
        _instance = new ScoreController();
    }
    
    return _instance;
}
