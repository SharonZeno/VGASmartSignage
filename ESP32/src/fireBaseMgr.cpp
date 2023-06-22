#include "fireBaseMgr.h"
#include <Firebase_ESP_Client.h>
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
// Insert Firebase project API Key
#define API_KEY "AIzaSyB2iGCEadrDLPOb72QrvW5vC2Kynnk11uE"
// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://vga-smart-signage---iot-default-rtdb.europe-west1.firebasedatabase.app/" 

//Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

unsigned long sendDataPrevMillis = 0;
bool signupOK = false;
int chosenTemplate = 0;

NFireBaseSetup::EDB_STATUS CFireBaseMgr::doSetup() {
  /* Assign the api key (required) */
  config.api_key = API_KEY;
  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;
  /* Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    signupOK = true;
  }
  else {
    return NFireBaseSetup::EDB_STATUS::E_ERROR_CONNECTION;
  }

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  Firebase.begin(&config, &auth);
  return NFireBaseSetup::EDB_STATUS::E_CONNECTED;
}

void CFireBaseMgr::setTemplate1Data() {
  if (Firebase.RTDB.getString(&fbdo, "/template/background_color")) {
    if (fbdo.dataType() == "string") {
      m_template1.backgroundColor = fbdo.stringData();
    }
  }
  if (Firebase.RTDB.getString(&fbdo, "/template/main_headline")) {
    if (fbdo.dataType() == "string") {
      m_template1.mainHeadline = fbdo.stringData();
    }
  }
  if (Firebase.RTDB.getString(&fbdo, "/template/task1")) {
    if (fbdo.dataType() == "string") {
      m_template1.task1 = fbdo.stringData();
    }
  }
  if (Firebase.RTDB.getString(&fbdo, "/template/task2")) {
    if (fbdo.dataType() == "string") {
      m_template1.task2 = fbdo.stringData();
    }
  }
  if (Firebase.RTDB.getString(&fbdo, "/template/task3")) {
    if (fbdo.dataType() == "string") {
      m_template1.task3 = fbdo.stringData();
    }
  }
  if (Firebase.RTDB.getString(&fbdo, "/template/task4")) {
    if (fbdo.dataType() == "string") {
      m_template1.task4 = fbdo.stringData();
    }
  }
  if (Firebase.RTDB.getString(&fbdo, "/template/task_background_color")) {
    if (fbdo.dataType() == "string") {
      m_template1.taskBackgroundColor = fbdo.stringData();
    }
  }
}

void CFireBaseMgr::setTemplate2Data() {
}

NFireBaseSetup::EDB_STATUS CFireBaseMgr::doLoopLogic() {
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    if (Firebase.RTDB.getInt(&fbdo, "/template/template")) {
      if (fbdo.dataType() == "int") {
        chosenTemplate = fbdo.intData();
        if (chosenTemplate == 1) {
          chosenTemplate = 1;
          setTemplate1Data();
        }
        else {
          chosenTemplate = 2;
          //setTemplate2Data();
        }
      }
    }
    else {
      return NFireBaseSetup::EDB_STATUS::E_ERROR_EMPTY;
    }
    if (Firebase.RTDB.getString(&fbdo, "/template/id")) {
      if (fbdo.dataType() == "string") {
        m_currentTemplateId = fbdo.stringData();
      }
    }
  }
}

int CFireBaseMgr::getChosenTemplate() {
  return m_chosenTemplate;
}

template1Data CFireBaseMgr::getTemplate1Data() {
  return m_template1;
}

template2Data CFireBaseMgr::getTemplate2Data() {
  return m_template2;
}
