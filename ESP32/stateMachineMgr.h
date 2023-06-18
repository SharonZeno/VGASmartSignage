#ifndef _STATEMACHINEMGR
#define _STATEMACHINEMGR

namespace NStateMachine
{
    enum ESystemState
    {
        E_BOOT,
        E_WIFI_INIT,
        E_ERROR_WIFI,
        E_MODE_SELECTION,
        E_DB_MODE,
        E_MANUAL_MODE,
        E_ERROR_EMPTY_DB,
        E_ERROR_CONNECTION_DB,
        E_SHOW_SIGNAGE
    };
};


class CStateMachineMgr
{
public:
    CStateMachineMgr();
    void doSetup();
    void doLoopLogic();
    NStateMachine::ESystemState getSystemState();
    void setSystemState(NStateMachine::ESystemState new_state);

private:
    NStateMachine::ESystemState m_systemState;
};

#endif