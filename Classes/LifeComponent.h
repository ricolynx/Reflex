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
        private:
            bool showLogs;
            int maxLife;
        public:
            int life;
            LifeComponent(int l);
            ~LifeComponent();
            int getMaxLife();
        
            LifeComponent& operator++ ();
            LifeComponent& operator-- ();
    };
}

#endif /* defined(__Reflex__LifeComponent__) */
