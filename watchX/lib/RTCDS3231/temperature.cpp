#include <Arduino.h>
#include "temperature.h"
#include <Wire.h>
float temperature=NAN;


void get3231Temp()
{
  //temp registers (11h-12h) get updated automatically every 64s
  Wire.beginTransmission(0x68);
  Wire.write(0x11);
  Wire.endTransmission();
  Wire.requestFrom(0x68, 2);

  if(Wire.available()) {
   unsigned char tMSB = Wire.read(); //2's complement int portion
   unsigned char tLSB = Wire.read(); //fraction portion

    temperature=  (tMSB & B01111111)+ //do 2's math on Tmsb
     ( (tLSB >> 6) * 0.25 ); //only care about bits 7 & 8
  }


}
