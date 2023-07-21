#ifndef _FIREBASEMGR
#define _FIREBASEMGR

#include "templates.h"
#include <Firebase_ESP_Client.h>

namespace NFireBaseSetup
{
    enum EDB_STATUS
    {
        E_CONNECTED,
        E_ERROR_CONNECTION,
        E_ERROR_EMPTY,
        GOOD
    };
};

class CFireBaseMgr
{
private:
    int m_chosenTemplate;
    template1Data m_template1;
    template2Data m_template2;
    char* m_currentTemplateId;
    void setTemplate1Data();
    //void setTemplate2Data();
    FirebaseData fbdo;
    FirebaseAuth auth;
    FirebaseConfig config;
    unsigned long sendDataPrevMillis;
    bool signupOK;
    int chosenTemplate;
public:
    CFireBaseMgr();
    ~CFireBaseMgr();
    NFireBaseSetup::EDB_STATUS doSetup();
    NFireBaseSetup::EDB_STATUS doLoopLogic();
    int getChosenTemplate(); 
    template1Data getTemplate1Data();
    template2Data getTemplate2Data();
};

#endif