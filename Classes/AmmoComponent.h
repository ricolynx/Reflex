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

namespace component
{
    class AmmoComponent : public Component
    {
        public:
            AmmoComponent(unsigned int max, unsigned int current);
        
            ~AmmoComponent();
        
            void shoot();
        
            void recharge();
        
        private:
            //max ammo the player can have
            unsigned int _maxAmmo;
        
            //current ammo
            unsigned int _currentAmmo;
        
            //show logs or not
            bool showlogs;
    };
}
#endif /* defined(__Reflex__AmmoComponent__) */
