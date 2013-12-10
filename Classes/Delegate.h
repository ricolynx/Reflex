//
//  Delegate.h
//  Reflex
//
//  Created by Eric Giraud on 08/12/2013.
//
//

#ifndef __Reflex__Delegate__
#define __Reflex__Delegate__

#include <iostream>

class Delegate
{
    public:
        virtual void invoke() = 0;
        virtual ~Delegate();
    protected:
        Delegate();
};


#endif /* defined(__Reflex__Delegate__) */
