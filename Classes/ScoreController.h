//
//  ScoreController.h
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#ifndef __Reflex__ScoreController__
#define __Reflex__ScoreController__

#include <iostream>
#include <vector>
#include "ScoreAction.h"
#include "ScoreObserver.h"



//class used to manage scores - Singleton -
class ScoreController
{
    private :
    
        static ScoreController* _instance;
    
        ScoreController();
        virtual ~ScoreController();
    
        long _currentScore;

        std::vector<ScoreObserver*> _observers;
    
    public :
    
        static ScoreController* Instance();
    
        long currentScore();
    
        void resetScore();
    
        long addAction(ScoreAction scoreAction);
    
        void attach(ScoreObserver* scoreObs);
    
        void detach(ScoreObserver* scoreObs);
    
        void notify(ScoreAction action);
};

#endif /* defined(__Reflex__ScoreController__) */
