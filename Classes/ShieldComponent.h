//
//  ShieldComponent.h
//  Reflex
//
//  Created by Eric Giraud on 15/12/2013.
//
//

#ifndef __Reflex__ShieldComponent__
#define __Reflex__ShieldComponent__

#include <iostream>
#include "Component.h"
namespace component
{
    class ShieldComponent : public Component
    {
        public:
            ShieldComponent();
            ~ShieldComponent();
        private:
            unsigned int val;
    };
}
#endif /* defined(__Reflex__ShieldComponent__) */
