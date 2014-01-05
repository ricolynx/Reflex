//
//  ScoreAction.cpp
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#include "ScoreAction.h"


ScoreAction:: ScoreAction(ACTION_TYPE t, int sId)
{
    this->type = t;
    this->shootId = sId;
    this->score = 0;
}

ScoreAction::~ScoreAction()
{
    
}