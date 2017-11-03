#include <Arduino.h>
#include <Wire.h>
#include <SeeedOLED.h>
#include <pgmspace.h>

void displaySetup(void){
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
