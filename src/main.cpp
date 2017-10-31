#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>
#include <Wire.h>
#include <SeeedOLED.h>
#include <pgmspace.h>

#define BUILD_VERSION        REPLACE_WITH_CURRENT_VERSION
#define ULR_FIRMWARE_BIN     "http://s3.amazonaws.com/feelflight/firmware/blouse.bin"
#define URL_FIRMWARE_VERSION "http://s3.amazonaws.com/feelflight/firmware/blouse.version"

void checkForNewFirmware(void){

    HTTPClient http;
    http.begin(URL_FIRMWARE_VERSION);
    int httpCode = http.GET();

    if(httpCode == HTTP_CODE_OK) {
        String payload = http.getString();
        int newVersion = payload.toInt();

        if (BUILD_VERSION < newVersion){
            Serial.println("I need to update");
            t_httpUpdate_return ret = ESPhttpUpdate.update(ULR_FIRMWARE_BIN);

            if (ret == HTTP_UPDATE_FAILED){
                Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str());
            }
        }
    }
}

void connectToWifi(void){

  WiFi.begin("WLANSSID", "WLANPASSWD");

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

}

void setup(){
    Serial.begin(115200);

    for(uint8_t t = 5; t > 0; t--) {
        Serial.printf("[SETUP] WAIT %d...\n", t);
        Serial.flush();
        delay(500);
    }

    Serial.print("My version:");
    Serial.println(BUILD_VERSION);

    Wire.begin();
    SeeedOled.init();
    SeeedOled.setNormalDisplay();
    //SeeedOled.setInverseDisplay();
    SeeedOled.clearDisplay();
    SeeedOled.setBrightness(255);
    SeeedOled.setPageMode();
    SeeedOled.setTextXY(0,0);
    SeeedOled.putString("Feelflight!");
    SeeedOLED.setTextXY(0,1);
    SeeedOled.putString("Version 1...");
    SeeedOLED.setTextXY(0,2);
    SeeedOled.putString("Connect to wifi");

    connectToWifi();
}

void loop(){
  checkForNewFirmware();
  delay(60000);
}
