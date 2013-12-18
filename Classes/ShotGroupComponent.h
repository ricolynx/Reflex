//
//  ShotGroupComponent.h
//  Reflex
//
//  Created by Eric Giraud on 18/12/2013.
//
//

#ifndef __Reflex__ShotGroupComponent__
#define __Reflex__ShotGroupComponent__

#include <iostream>
#include "Component.h"

namespace component
{
    class ShotGroupComponent : public Component
    {
        public:
            ShotGroupComponent(int gId);
            ~ShotGroupComponent();
            int groupId;
    };
}

#endif /* defined(__Reflex__ShotGroupComponent__) */
