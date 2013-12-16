//
//  ParticleComponent.h
//  Reflex
//
//  Created by Eric Giraud on 16/12/2013.
//
//

#ifndef __Reflex__ParticleComponent__
#define __Reflex__ParticleComponent__

#include <iostream>
#include "Component.h"
namespace component
{
    class ParticleComponent : public Component
    {
        public:
            ParticleComponent(std::string partName);
            ~ParticleComponent();
        
            std::string particleName;
    };
}
#endif /* defined(__Reflex__ParticleComponent__) */
