#ifndef _FIREBASEMGR
#define _FIREBASEMGR

#include <string>
#include "templates.h"

namespace NFireBaseSetup
{
    enum EDB_STATUS
    {
        E_CONNECTED,
        E_ERROR_CONNECTION,
        E_ERROR_EMPTY,
    };
};

class CFireBaseMgr
{
private:
    int m_chosenTemplate;
    template1Data m_template1;
    template2Data m_template2;
    String m_currentTemplateId;
    void setTemplate1Data();
    void setTemplate2Data();
public:
    CFireBaseMgr() = default;
    NFireBaseSetup::EDB_STATUS doSetup();
    NFireBaseSetup::EDB_STATUS doLoopLogic();
    int getChosenTemplate(); 
    template1Data getTemplate1Data();
    template2Data getTemplate2Data();
};

#endif