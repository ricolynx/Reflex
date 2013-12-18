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

//class used to manage scores - Singleton -
class ScoreController
{
    private :
        ScoreController();
        virtual ~ScoreController();
        static ScoreController *_instance;
    public :
        static ScoreController *Instance();
};

#endif /* defined(__Reflex__ScoreController__) */
