#include "rtc.h"
#include "Wire.h"
//unsigned char seconds, minutes, hours, day, date, month, year;
volatile unsigned char   curtm[7] ;

void stopSqw(){

  Wire.beginTransmission(0x68);
  Wire.write(0x0e);        // set register address

    Wire.write(0B00100011);         // ... and send it from buffer

  Wire.endTransmission();
}
void startSqw(){

  Wire.beginTransmission(0x68);
  Wire.write(0x0e);        // set register address

    Wire.write(0B01100011);         // ... and send it from buffer

  Wire.endTransmission();
}
#define DS3231_I2C_ADDRESS 0x68
/*
// Convert normal decimal numbers to binary coded decimal
byte decToBcd(byte val)
{
  return( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
byte bcdToDec(byte val)
{
  return( (val/16*10) + (val%16) );
}
*/

void setDateTime( )
{
  // sets time and date data to DS3231
  year=18;
  date=28;
  day=2;
  month=2;
  seconds=57;
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set next input to start at the seconds register
  Wire.write(decToBcd(seconds)); // set seconds
  Wire.write(decToBcd(minutes)); // set minutes
  Wire.write(decToBcd(hours)); // set hours
  Wire.write(decToBcd(day)); // set day of week (1=Sunday, 7=Saturday)
  Wire.write(decToBcd(date)); // set date (1 to 31)
  Wire.write(decToBcd(month)); // set month
  Wire.write(decToBcd(year)); // set year (0 to 99)
  Wire.endTransmission();
}
void getDateTime( )
{
  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0); // set DS3231 register pointer to 00h
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7);
  // request seven bytes of data from DS3231 starting from register 00h
  curtm[0] = bcdToDec(Wire.read() & 0x7f);
  curtm[1] = bcdToDec(Wire.read());
  curtm[2] = bcdToDec(Wire.read() & 0x3f);
  curtm[3] = bcdToDec(Wire.read());
  curtm[4] = bcdToDec(Wire.read());
  curtm[5] = bcdToDec(Wire.read());
  curtm[6] = bcdToDec(Wire.read());
}
