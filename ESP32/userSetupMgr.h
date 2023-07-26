#ifndef _USERSETUPMGR
#define _USERSETUPMGR

#include "time.h"
#include <WiFi.h>
#include <WebServer.h>

namespace NUserSetup
{
    enum EWIFI_STATUS
    {
    E_CONNECTED,
    E_WRONG_WIFI_DETAILS,
    };
};


class CUserSetupMgr
{
public:
    CUserSetupMgr() = default;
    ~CUserSetupMgr() = default;
    void doSetup();
    NUserSetup::EWIFI_STATUS doLoopLogic();
    tm& getNTPValue();
};

#endif