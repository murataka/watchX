#ifndef BATTERY_H
#define BATTERY_H


#include <Arduino.h>

//#include <ssd1306.h>
//#include "watchX.h"
//#include "resources.h"



#define CHARGE_PIN 5

unsigned long readBattery(uint8_t b_en_pin,uint8_t bat_pin);
extern unsigned long batterylevel;
extern unsigned long batteryread;


extern uint8_t DEVICESTATE;



#endif
