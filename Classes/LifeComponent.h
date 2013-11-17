//
//  LifeComponent.h
//  Reflex
//
//  Created by Eric Giraud on 17/11/2013.
//
//

#ifndef __Reflex__LifeComponent__
#define __Reflex__LifeComponent__

#include <iostream>
#include "Component.h"

namespace component
{
    class LifeComponent : public Component
    {
        public:
            int life = 1;
            LifeComponent(int l);
            ~LifeComponent();
    };
}

#endif /* defined(__Reflex__LifeComponent__) */
