#include <Wire.h>
#include "tinyMpu6050.h"


void startMpu6050(){

  Wire.begin();
    Wire.beginTransmission(0x69);
    Wire.write(0x6B);  // PWR_MGMT_1 register
    Wire.write(0);     // set to zero (wakes up the MPU-6050)
    Wire.endTransmission(true);

}
void updateMpu6050(){

  Wire.beginTransmission(0x69);
   Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
   Wire.endTransmission(false);
   Wire.requestFrom(0x69,14,true);  // request a total of 14 registers
for(uint8_t a=0;a<7;a++)
   ac[a]=Wire.read()<<8|Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
   
}
