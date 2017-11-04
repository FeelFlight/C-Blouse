#include <Arduino.h>
#include <Wire.h>
#include <SeeedOLED.h>
#include <pgmspace.h>
#include "display.h"
#include "pin.h"

void displaySetup(void){
    displayPower(true);
    Wire.begin();
    SeeedOled.init();
    SeeedOled.setNormalDisplay();
    SeeedOled.clearDisplay();
    SeeedOled.setBrightness(0);
    SeeedOled.setPageMode();
    uint8_t l = 0;
    SeeedOled.setTextXY(l++, 0);
    SeeedOled.putString("   Feelflight");
    SeeedOled.setTextXY(l++, 0);
    SeeedOled.putString("   ==========");
    SeeedOled.setTextXY(l++, 0);
    SeeedOled.putString("    (c)Carla");
    SeeedOled.setTextXY(l++, 0);
    SeeedOled.setTextXY(l++, 0);
}

void displaySetLine(uint8_t line, const char* text){
    SeeedOled.setTextXY(line, 0);
    SeeedOled.putString("                ");
    SeeedOled.setTextXY(line, 0);
    SeeedOled.putString(text);
}

void displayIntensity(uint8_t intensity){
    SeeedOled.setBrightness(intensity);
}

void displayInverted (bool state){
  if(state){
    SeeedOled.setInverseDisplay();
  }else{
    SeeedOled.setNormalDisplay();
  }
}

void displayPower(bool state){
    if (state){
        digitalWrite(PIN_DISPLAY, true);
    }else{
        digitalWrite(PIN_DISPLAY, false);
    }

}