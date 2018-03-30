#include "mag3110.h"
void MAG3110_begin(){

  // Start I2C Transmission
 Wire.beginTransmission(0x0E);
 // Select control register-1
 Wire.write(0x10);
 // Set active mode enabled
 Wire.write(0x01);
 // Stop I2C Transmission
 Wire.endTransmission();

}
