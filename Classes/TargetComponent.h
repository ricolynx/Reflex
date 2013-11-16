//
//  TargetComponent.h
//  Reflex
//
//  Created by Eric Giraud on 16/11/2013.
//
//

#ifndef __Reflex__TargetComponent__
#define __Reflex__TargetComponent__

#include <iostream>
#include "Component.h"
#include "Entity.h"

class Entity;
namespace component{

    class TargetComponent : public Component
    {
        private:
            //the target
            Entity *myTarget;

        public:
            //Constructor
            TargetComponent(Entity *t);
        
            //Destructor
            virtual ~TargetComponent();
        
            //get the target
            Entity* getTarget();
        
            //set a new target
            void setNewTarget(Entity *t);
    };
}

#endif /* defined(__Reflex__TargetComponent__) */
