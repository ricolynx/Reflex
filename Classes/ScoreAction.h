//
//  ScoreAction.h
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#ifndef __Reflex__ScoreAction__
#define __Reflex__ScoreAction__

#include <iostream>

struct ScoreAction
{
    enum ACTION_TYPE {
        destroyPlanet = 100,
        shootPlanet = 50,
        shootBonus = 50,
        getBonus = 100
    };
    
    //type of the action
    ACTION_TYPE type;
    
    //shoot id if the action is related to a shoot Id
    int shootId;
    
    int score;
    
    ScoreAction(ACTION_TYPE t, int sId = -1);
    ~ScoreAction();
};

#endif /* defined(__Reflex__ScoreAction__) */
