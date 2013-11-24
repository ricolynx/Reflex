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
        
            bool showLogs;
        
            //the target
            std::shared_ptr<Entity> myTarget;

        public:
            //Constructor
            TargetComponent(std::shared_ptr<Entity>t);
        
            //Destructor
            virtual ~TargetComponent();
        
            //get the target
            std::shared_ptr<Entity> getTarget();
        
            //set a new target
            void setNewTarget(std::shared_ptr<Entity> t);
    };
}

#endif /* defined(__Reflex__TargetComponent__) */
