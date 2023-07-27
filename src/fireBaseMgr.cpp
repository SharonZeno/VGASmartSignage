#include "fireBaseMgr.h"
//Provide the token generation process info.
#include "addons/TokenHelper.h"
//Provide the RTDB payload printing info and other helper functions.
#include "addons/RTDBHelper.h"
#include "secrets.h"
#include "parameters.h"
#include <string>
// Insert RTDB URLefine the RTDB URL */
#define DATABASE_URL "https://vga-smart-signage---iot-default-rtdb.europe-west1.firebasedatabase.app/" 

CFireBaseMgr::CFireBaseMgr() : sendDataPrevMillis(0), signupOK(false), m_chosenTemplate(0), 
    m_template1(), fbdo(), auth(), config() {};

CFireBaseMgr::~CFireBaseMgr() = default;

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
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/BackgroundColor"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template1.backgroundColor, fbdo.stringData().c_str(), 7); 
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/MainHeadline"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template1.mainHeadline, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/Task1"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template1.task1, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/Task2"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template1.task2, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/Task3"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template1.task3, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/TaskBackgroundColor"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template1.taskBackgroundColor, fbdo.stringData().c_str(), 7);
    }
  }
}

void CFireBaseMgr::setTemplate2Data() {
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/MainHeadline"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.mainHeadline, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/FirstFloorHeadline"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.firstFloorHeadline, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/FirstFloorBackgroundColor"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.firstFloorBackgroundColor, fbdo.stringData().c_str(), 7);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/FirstFloorClassDesc1"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.firstFloorClassDesc1, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/FirstFloorClassDesc2"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.firstFloorClassDesc2, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/FirstFloorClassDesc3"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.firstFloorClassDesc3, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/FirstFloorClassDesc4"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.firstFloorClassDesc4, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/SecondFloorHeadline"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.secondFloorHeadline, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/SecondFloorBackgroundColor"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.secondFloorBackgroundColor, fbdo.stringData().c_str(), 7);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/SecondFloorClassDesc1"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.secondFloorClassDesc1, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/SecondFloorClassDesc2"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.secondFloorClassDesc2, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/SecondFloorClassDesc3"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.secondFloorClassDesc3, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/SecondFloorClassDesc4"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.secondFloorClassDesc4, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/ThirdFloorHeadline"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.thirdFloorHeadline, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/ThirdFloorBackgroundColor"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.thirdFloorBackgroundColor, fbdo.stringData().c_str(), 7);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/ThirdFloorClassDesc1"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.thirdFloorClassDesc1, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/ThirdFloorClassDesc2"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.thirdFloorClassDesc2, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/ThirdFloorClassDesc3"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.thirdFloorClassDesc3, fbdo.stringData().c_str(), 50);
    }
  }
  if (Firebase.RTDB.getString(&fbdo, CONTROLLER_ID + std::string("/ThirdFloorClassDesc4"))) {
    if (fbdo.dataType() == "string") {
      memcpy(m_template2.thirdFloorClassDesc4, fbdo.stringData().c_str(), 50);
    }
  }
}

NFireBaseSetup::EDB_STATUS CFireBaseMgr::doLoopLogic() {
  if (Firebase.ready() && signupOK && (millis() - sendDataPrevMillis > 15000 || sendDataPrevMillis == 0)) {
    sendDataPrevMillis = millis();
    std::string path = CONTROLLER_ID + std::string("/template");
    if (Firebase.RTDB.getInt(&fbdo, path)) {
      if (fbdo.dataType() == "int") {
        m_chosenTemplate = fbdo.intData();
        if (m_chosenTemplate == 1) {
          setTemplate1Data();
        }
        else {
          setTemplate2Data();
        }
      }
    }
    else {
      return NFireBaseSetup::EDB_STATUS::E_ERROR_EMPTY;
    }
  }
  return NFireBaseSetup::EDB_STATUS::GOOD;
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