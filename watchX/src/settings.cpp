#include <Arduino.h>
#include <EEPROM.h>
#include "bluetooth.h"
#include "oled.h"
#include "watchX.h"
const char title[] PROGMEM = "< SETTINGS >";
const char items[][10] PROGMEM={"Off","On"};
uint8_t devices;

void drawSettings(){


  drawString_P(28,0,title,smallFont);


drawString_P(110,8,items[devices&0B1==1?1:0 ],smallFont);


}

void settingsSw1(){

devices|=0B1;
EEPROM.write(0,devices);

ble_connect();
}

void settingsSw2(){

devices=devices&0B11111110;
EEPROM.write(0,devices);
ble.end();
}
