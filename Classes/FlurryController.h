//
//  FlurryController.h
//  Reflex
//
//  Created by Eric Giraud on 30/11/2013.
//
//

#ifndef __Reflex__FlurryController__
#define __Reflex__FlurryController__

#include <iostream>
#include "cocos2d.h"
#include "PluginManager.h"
#include "ProtocolAnalytics.h"

//singleton to control flurry
class FlurryController
{
    public:
        static FlurryController *Instance();
    
    private:
        bool showLogs;
        static FlurryController *_instance;
        cocos2d::plugin::ProtocolAnalytics *pFlurry;
    
    protected:
        FlurryController();
    
    public:
        virtual ~FlurryController();
        void startSession();
        void stopSession();
        void logSimpleEvent(const char *eventName);
};

#endif /* defined(__Reflex__FlurryController__) */
