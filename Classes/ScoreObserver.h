//
//  ScoreObserver.h
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#ifndef __Reflex__ScoreObserver__
#define __Reflex__ScoreObserver__

#include <iostream>
#include "ScoreAction.h"
class ScoreObserver
{
    public:
        ScoreObserver();
        virtual ~ScoreObserver();
        virtual void update (ScoreAction action, int newScore);
};


#endif /* defined(__Reflex__ScoreObserver__) */
