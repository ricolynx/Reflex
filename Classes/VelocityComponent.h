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
            float speedX ;
            float speedY ;
            bool isMoving = true;
    };
}
#endif /* defined(__Reflex__VelocityComponent__) */
