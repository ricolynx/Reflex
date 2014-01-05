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
    
        static const int NB_BULLETS = 4;
    
        static ScoreController* _instance;
    
        //int bulletCounters [100] = { };
        //int v [100] = { };
        std::vector<int> bulletCounters;
        std::vector<int> scoreCounter;

        ScoreController();
        virtual ~ScoreController();
    
        long _currentScore;

        std::vector<ScoreObserver*> _observers;
    
    public :
    
        static ScoreController* Instance();
    
        long currentScore();
    
        void resetScore();
    
        long addAction(ScoreAction scoreAction);
    
        void addBulletCount(int salveId);
    
        void attach(ScoreObserver* scoreObs);
    
        void detach(ScoreObserver* scoreObs);
    
        void notify(ScoreAction action);
};

#endif /* defined(__Reflex__ScoreController__) */
