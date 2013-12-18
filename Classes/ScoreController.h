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
#include "ScoreAction.h"


//class used to manage scores - Singleton -
class ScoreController
{
    private :
    
        static ScoreController* _instance;
    
        ScoreController();
        virtual ~ScoreController();
    
        long _currentScore;
    
    public :
    
        static ScoreController* Instance();
    
        long currentScore();
    
        void resetScore();
    
        long addAction(ScoreAction scoreAction);
};

#endif /* defined(__Reflex__ScoreController__) */
