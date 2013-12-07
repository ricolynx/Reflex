//
//  BonusComponent.h
//  Reflex
//
//  Created by Eric Giraud on 07/12/2013.
//
//

#ifndef __Reflex__BonusComponent__
#define __Reflex__BonusComponent__

#include <iostream>
#include "Component.h"

namespace component
{
    class BonusComponent : public Component
    {
    public:
        
        //enums the different types of entities
        enum BONUS_TYPE {
            ammo,
            life
        };
 
        
    public:
        BonusComponent(BONUS_TYPE newType);
        
        ~BonusComponent();
        
        BONUS_TYPE getType();
        
    private:
        
        BONUS_TYPE type;
        
        //show logs or not
        bool showLogs;
    };
}
#endif /* defined(__Reflex__BonusComponent__) */
