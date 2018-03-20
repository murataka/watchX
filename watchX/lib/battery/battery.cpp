
#include <Arduino.h>
#include "battery.h"
//#include <nano_gfx.h>




//extern   unsigned char buf[128*64/8];
//extern  NanoCanvas c;
extern unsigned char DEVICESTATE;
 unsigned long batterylevel=0;
unsigned long batteryread=0;





unsigned long readBattery(uint8_t b_en_pin,uint8_t bat_pin){
  float val=batterylevel;


    digitalWrite(b_en_pin,HIGH);
    delayMicroseconds(200);
    val=analogRead(bat_pin)*152.83;
     digitalWrite(b_en_pin,LOW);
     //batteryread=millis();


   return val;
  }
