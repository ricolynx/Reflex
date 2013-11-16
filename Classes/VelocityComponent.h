//
//  VelocityComponent.h
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#ifndef __Reflex__VelocityComponent__
#define __Reflex__VelocityComponent__

#include <iostream>
#include "Component.h"

class Entity;
namespace component{

    class VelocityComponent : public Component
    {
        public :
            VelocityComponent();
            virtual ~VelocityComponent();
            int speedX = 0;
            int speedY = 0;
    };
}
#endif /* defined(__Reflex__VelocityComponent__) */
