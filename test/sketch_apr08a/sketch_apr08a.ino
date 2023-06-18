#include <WiFi.h>
#include <WebServer.h>
#include "time.h"

//true: creates an access point, false: connects to an existing wifi
const bool AccessPointMode = true;
//wifi credentials (enter yours if you arne not using the AccessPointMode)
const char *ssid = "VGA";
const char *password = "";
const char* ntpServer = "pool.ntp.org";
const long gmtOffset_sec = 10800;
const int daylightOffset_sec = 0;

void printLocalTime() {
  struct tm timeinfo;
  if (!getLocalTime(&timeinfo)) {
    Serial.println("Falid to obtain time");
    return;
  }
  Serial.println(&timeinfo, "%A, %B %d %Y %H:%M:%S");
}

WebServer server(80); // create a web server on port 80

void handleRoot() { // handle root URL
  server.send(200, "text/html", "<form method='POST' action='/connect'><label for='ssid'>WiFi Name:</label><input type='text' name='ssid'><br><label for='password'>Password:</label><input type='password' name='password'><br><input type='submit' value='Connect'></form>"); // display form to input WiFi name and password
}

void handleConnect() { // handle connect URL
  WiFi.begin(server.arg("ssid").c_str(), server.arg("password").c_str()); // connect to WiFi network
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("CONNECTED");
  configTime(gmtOffset_sec, daylightOffset_sec, ntpServer);
  printLocalTime();
  Serial.println(server.arg("ssid").c_str());
  server.send(200, "text/html", "<h1>Connected to WiFi network</h1>"); // display success message
}

void setup() {
  Serial.begin(115200);
  //Handle the WiFi AP or STA mode and display results on the screen
  if (AccessPointMode)
  {
    Serial.println("Creating access point...");
    WiFi.softAP(ssid, password, 6, 0);
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

void loop() {
  server.handleClient(); // handle incoming client requests
  if (WiFi.status() != WL_CONNECTED) { // if not connected to WiFi network
    Serial.println("Connecting to WiFi network..."); // display connection message
    delay(1000); // wait for connection
  }
  else {
    Serial.println("CONNECTED");
    delay(1000); // wait for connection
    printLocalTime();
  }
}
