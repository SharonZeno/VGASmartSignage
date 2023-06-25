#include "userSetupMgr.h"



//true: creates an access point, false: connects to an existing wifi
const bool AccessPointMode = true;
//wifi credentials (enter yours if you arne not using the AccessPointMode)
const char *ssid = "VGA Smart Signage";
const char *password = "";

const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 10800;
const int daylightOffset_sec = 0;
WebServer server(80); // create a web server on port 80

 struct tm timeinfo;

tm& CUserSetupMgr::getNTPValue()
{
  return timeinfo;
}


void saveLocalTime()
{
 
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Falid to obtain time");
    return;
  }
}

void handleConnect()
{

  WiFi.begin(server.arg("ssid").c_str(), server.arg("password").c_str()); // connect to WiFi network
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  saveLocalTime();
  Serial.println(server.arg("ssid").c_str());
  server.send(200, "text/html", "<h1>Connected to WiFi network</h1>"); // display success message

}

void handleRoot()
{
  server.send(200, "text/html", "<form method='POST' action='/connect'><label for='ssid'>WiFi Name:</label><input type='text' name='ssid'><br><label for='password'>Password:</label><input type='password' name='password'><br><input type='submit' value='Connect'></form>"); // display form to input WiFi name and password
}

void CUserSetupMgr::doSetup()
{
    //Handle the WiFi AP or STA mode and display results on the screen
    if (AccessPointMode)
    {
        Serial.println("Creating access point...");

        Serial.print("get free heap - before WiFi.softAP(ssid, password);");
        Serial.println(ESP.getFreeHeap());
        Serial.print("get min free heap - before WiFi.softAP(ssid, password;");
        Serial.println(ESP.getMinFreeHeap());

        // WiFi.softAP(ssid, password, 6, 0);
        WiFi.softAP(ssid, password);

        Serial.print("get free heap - after WiFi.softAP(ssid, password);");
        Serial.println(ESP.getFreeHeap());
        Serial.print("get min free heap - after WiFi.softAP(ssid, password);");
        Serial.println(ESP.getMinFreeHeap());
    }
    else
    {
        Serial.print("Connecting to SSID ");
        Serial.println(ssid);
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED)
        {
            delay(500);
        }
    }
    WiFi.disconnect(); // disconnect from any previously connected network
    delay(1000); // wait for disconnection to complete 
    server.on("/", handleRoot); // handle root URL
    server.on("/connect", handleConnect); // handle connect URL
    server.begin(); // start web server
}


NUserSetup::EWIFI_STATUS CUserSetupMgr::doLoopLogic()
{
  int time_count = 0;
  while(true)
  {
    //TODO: make this functionality only if system state is ok
    server.handleClient(); // handle incoming client requests
    if (WiFi.status() != WL_CONNECTED) { // if not connected to WiFi network
        if(time_count > 20)
        {
          //After 20 seconds it coulnd't connect to Wifi, needs to start again.
          return NUserSetup::E_WRONG_WIFI_DETAILS;
        }
        Serial.println("Connecting to WiFi network..."); // display connection message
        delay(1000); // wait for connection
        time_count ++;
    }
    else {
        Serial.println("CONNECTED");
        delay(1000); // wait for connection
        saveLocalTime();
        return NUserSetup::E_CONNECTED;
    }
  }
}