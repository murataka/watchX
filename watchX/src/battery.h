#ifndef BATTERY_H
#define BATTERY_H
//#include <ssd1306.h>
#include "watchX.h"
#include "resources.h"




 float readBattery();
extern float batterylevel;
extern unsigned long batteryread;


extern unsigned char DEVICESTATE;

void updateThings( );

void drawBattery( );

#endif
