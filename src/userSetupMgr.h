#ifndef _USERSETUPMGR
#define _USERSETUPMGR

#include <WiFi.h>
#include <WebServer.h>
#include "time.h"

class CUserSetupMgr
{
public:
    CUserSetupMgr() = default;
    void doSetup();
    void doLoopLogic();
    // tm& getTime();
    //getManaulData();

};

#endif