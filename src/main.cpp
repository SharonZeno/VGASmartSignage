#include <WiFiManager.h>
#include "fabgl.h"
#include "fabui.h"
#include "template1.h"
#include "stateMachineMgr.h"
#include "fireBaseMgr.h"
#include "time.h"
#include "template2.h"
#include "bitmapsWarehouse.h"

fabgl::VGAController DisplayController;
CStateMachineMgr stateMachineMgr;
 

Bitmap arrow_bitmap = Bitmap(72, 72, &NBitmapsWarehouse::arrow[0], PixelFormat::RGBA2222);
Bitmap good_luck_bitmap = Bitmap(72, 72, &NBitmapsWarehouse::good_luck[0], PixelFormat::RGBA2222);
Sprite sprites[1];
int chosenTemplate = 0;
template1Data _template1;
template2Data _template2;
char ssid_wifi[50];
char wifi_pass[50];
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 10800;
const int daylightOffset_sec = 0;
struct tm _timeinfo;
bool setup_done = false;
bool db_mode = false;
bool connection_result = true;
WiFiManager* pWiFiManager = nullptr;
CFireBaseMgr* pFireBaseMgr = nullptr;


void setup()
{
  Serial.begin(115200);
}

void loop()
{
  switch (stateMachineMgr.getSystemState())
  {
  case NStateMachine::E_BOOT:
    
    //Note: Mode selection is inside this manger.
    pWiFiManager = new WiFiManager();
    connection_result = pWiFiManager->autoConnect("VGA Smart Signage");
    if (pWiFiManager->_mode == "DB") {
      db_mode = true;
      if(!connection_result)
      {
        stateMachineMgr.setSystemState(NStateMachine::E_ERROR_WIFI);
        break;
      }
      configTime(gmtOffset_sec, daylightOffset_sec, ntpServer); //get current time
      if (!getLocalTime(&_timeinfo)) {
        Serial.println("Falid to obtain time");
      }
      memcpy(ssid_wifi, (pWiFiManager->getWiFiSSID()).c_str(),50); //for reconnecting in the next iterations
      memcpy(wifi_pass, (pWiFiManager->getWiFiPass()).c_str(),50);
      stateMachineMgr.setSystemState(NStateMachine::E_DB_MODE);
    }
    else {
      stateMachineMgr.setSystemState(NStateMachine::E_MANUAL_MODE);
    }
    break;
  case NStateMachine::E_ERROR_WIFI:
  {
    pWiFiManager->disconnect();
    pWiFiManager->erase();
    pWiFiManager->resetSettings();
    delete pWiFiManager;
    DisplayController.begin();
    DisplayController.setResolution(VGA_640x350_70Hz);
    fabgl::Canvas cv(&DisplayController);
    cv.setPenColor(Color::Red);
    cv.drawText(100, 100, "Error connecting to WIFI, please try again");
    delay(30000);
    ESP.restart();
  }
  case NStateMachine::E_DB_MODE:
    pFireBaseMgr = new CFireBaseMgr();
    if(pFireBaseMgr->doSetup() == NFireBaseSetup::E_ERROR_CONNECTION)
    {
      stateMachineMgr.setSystemState(NStateMachine::E_ERROR_CONNECTION_DB);
      break;
    }
    if(pFireBaseMgr->doLoopLogic() == NFireBaseSetup::E_ERROR_EMPTY)
    {
      stateMachineMgr.setSystemState(NStateMachine::E_ERROR_EMPTY_DB);
      break;
    }
    chosenTemplate = pFireBaseMgr->getChosenTemplate();
    if (chosenTemplate == 1) {
      _template1 = pFireBaseMgr->getTemplate1Data();
    }
    else {
      _template2 = pFireBaseMgr->getTemplate2Data();
    }
    delete pFireBaseMgr;
    pWiFiManager->disconnect();
    pWiFiManager->erase();
    pWiFiManager->resetSettings();
    delete pWiFiManager;
    stateMachineMgr.setSystemState(NStateMachine::E_SHOW_SIGNAGE);
    break;
  case NStateMachine::E_ERROR_CONNECTION_DB:
  {
    delete pFireBaseMgr;
    pWiFiManager->disconnect();
    pWiFiManager->erase();
    pWiFiManager->resetSettings();
    delete pWiFiManager;
    DisplayController.begin();
    DisplayController.setResolution(VGA_640x350_70Hz);
    fabgl::Canvas cv(&DisplayController);
    cv.setPenColor(Color::Red);
    cv.drawText(100, 100, "Error connecting to DB, please try again");
    delay(30000);
    ESP.restart();
  }
  case NStateMachine::E_ERROR_EMPTY_DB:
  {
    delete pFireBaseMgr;
    pWiFiManager->disconnect();
    pWiFiManager->erase();
    pWiFiManager->resetSettings();
    delete pWiFiManager;
    DisplayController.begin();
    DisplayController.setResolution(VGA_640x350_70Hz);
    fabgl::Canvas cv(&DisplayController);
    cv.setPenColor(Color::Red);
    cv.drawText(100, 100, "Error DB is empty");
    delay(30000);
    ESP.restart();
  }
  case NStateMachine::E_MANUAL_MODE:
    if(pWiFiManager->_template == "1") {
      Serial.println("here in manual mode template 1"); //for testing
      chosenTemplate = 1;
      memcpy(_template1.mainHeadline, pWiFiManager->_t1headline.c_str(), 50);
      memcpy(_template1.task1, pWiFiManager->_task1.c_str(), 50);
      memcpy(_template1.task2, pWiFiManager->_task2.c_str(), 50);
      memcpy(_template1.task3, pWiFiManager->_task3.c_str(), 50);
    }
    else {
      chosenTemplate = 2;
      memcpy(_template2.mainHeadline, pWiFiManager->_t2headline.c_str(), 50);
      memcpy(_template2.firstFloorHeadline, pWiFiManager->_f1headline.c_str(), 50);
      memcpy(_template2.firstFloorClassDesc1, pWiFiManager->_f1desc1.c_str(), 50);
      memcpy(_template2.firstFloorClassDesc2, pWiFiManager->_f1desc2.c_str(), 50);
      memcpy(_template2.firstFloorClassDesc3, pWiFiManager->_f1desc3.c_str(), 50);
      memcpy(_template2.firstFloorClassDesc4, pWiFiManager->_f1desc4.c_str(), 50);
      memcpy(_template2.secondFloorHeadline, pWiFiManager->_f2headline.c_str(), 50);
      memcpy(_template2.secondFloorClassDesc1, pWiFiManager->_f2desc1.c_str(), 50);
      memcpy(_template2.secondFloorClassDesc2, pWiFiManager->_f2desc2.c_str(), 50);
      memcpy(_template2.secondFloorClassDesc3, pWiFiManager->_f2desc3.c_str(), 50);
      memcpy(_template2.secondFloorClassDesc4, pWiFiManager->_f2desc4.c_str(), 50);
      memcpy(_template2.thirdFloorHeadline, pWiFiManager->_f3headline.c_str(), 50);
      memcpy(_template2.thirdFloorClassDesc1, pWiFiManager->_f3desc1.c_str(), 50);
      memcpy(_template2.thirdFloorClassDesc2, pWiFiManager->_f3desc2.c_str(), 50);
      memcpy(_template2.thirdFloorClassDesc3, pWiFiManager->_f3desc3.c_str(), 50);
      memcpy(_template2.thirdFloorClassDesc4, pWiFiManager->_f3desc4.c_str(), 50);
    }
    pWiFiManager->disconnect();
    pWiFiManager->erase();
    pWiFiManager->resetSettings();
    delete pWiFiManager;
    stateMachineMgr.setSystemState(NStateMachine::E_SHOW_SIGNAGE);
    break;
  case NStateMachine::E_SHOW_SIGNAGE:
    if(!setup_done)
    {
      WiFi.softAPdisconnect(true);
      WiFi.disconnect(true, true);

      DisplayController.begin();
      DisplayController.setResolution(VGA_640x350_70Hz);

      //adjust this to center screen in your monitor
      DisplayController.moveScreen(0, 50);

      setup_done = true;
    }
    else //after first setup
    {  
      if (db_mode) {
        WiFi.mode(WIFI_STA); //Optional
        WiFi.begin(ssid_wifi, wifi_pass);
        while (WiFi.status() != WL_CONNECTED) { // if not connected to WiFi network
          delay(1000); // wait for connection
        }
        //get current time
        configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
        if (!getLocalTime(&_timeinfo)) {
          Serial.println("Falid to obtain time");
        }
        WiFi.softAPdisconnect(true);
        WiFi.disconnect(true, true);
      }   
    }
    if (chosenTemplate == 1) {
      // associates bitmaps to sprites
      sprites[0].addBitmap(&arrow_bitmap);

      // sets initial position
      sprites[0].moveTo(470, 120);
    
      // makes sprites visible
      sprites[0].visible = true;

      // add sprites to display controller
      DisplayController.setSprites(sprites, 1);
      if (db_mode) {
        Template1(&_template1, &_timeinfo).runForOneMinute(&DisplayController);
      }
      else {
        Template1(&_template1).run(&DisplayController); //static run
      }
    }
    else {
      sprites[0].addBitmap(&good_luck_bitmap);
      // sets initial position
      sprites[0].moveTo(490, 0);
    
      // makes sprites visible
      sprites[0].visible = true;

      // add sprites to display controller
      DisplayController.setSprites(sprites, 1);
      if (db_mode) {
        Template2(&_template2, &_timeinfo).runForOneMinute(&DisplayController);
        sprites[0].visible = false;
      }
      else {
        Template2(&_template2).run(&DisplayController); //static run
      }
    }
    break;

  default:
    stateMachineMgr.setSystemState(NStateMachine::E_BOOT);
    break;
  }
}