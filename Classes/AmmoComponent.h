//
//  AmmoComponent.h
//  Reflex
//
//  Created by Eric Giraud on 06/12/2013.
//
//

#ifndef __Reflex__AmmoComponent__
#define __Reflex__AmmoComponent__

#include <iostream>
#include "Component.h"

namespace component
{
    class AmmoComponent : public Component
    {
        public:
            AmmoComponent(int max, int current);
        
            ~AmmoComponent();
        
            void shoot();
        
            void recharge();
        
            int getAmmo();
        
        private:
            //max ammo the player can have
            int _maxAmmo;
        
            //current ammo
            int _currentAmmo;
        
            //show logs or not
            bool showLogs;
    };
}
#endif /* defined(__Reflex__AmmoComponent__) */
