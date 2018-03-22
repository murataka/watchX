#include "rtc.h"
#include "Wire.h"
//unsigned char seconds, minutes, hours, day, date, month, year;
volatile unsigned char   curtm[7] ;

void startSqw(){

  Wire.beginTransmission(0x68);
  Wire.write(0x0e);        // set register address

    Wire.write(0B01100011);         // ... and send it from buffer

  Wire.endTransmission();
}
void set3231Date()
{

  Wire.beginTransmission(DS3231_I2C_ADDRESS);
  Wire.write(0x00);
  for(char a=0;a<7;a++)
  Wire.write(decToBcd(curtm[a]));


  Wire.endTransmission();
}
uint8_t bcdToDec(uint8_t num, uint8_t mod){
  return (((num & mod)>>4)*10 + (num & 0B00001111));
  }

void get3231Date()
{
  // send request to receive data starting at register 0
  Wire.beginTransmission(DS3231_I2C_ADDRESS); // 104 is DS3231 device address
  Wire.write(0x00); // start at register 0
  Wire.endTransmission();
  Wire.requestFrom(DS3231_I2C_ADDRESS, 7); // request seven bytes

  if(Wire.available()) {
    int a=0;
    while(a!=7){
    curtm[a] = Wire.read(); // get seconds

    a++;
    }
   /* seconds = bcdToDec(seconds);// convert BCD to decimal
    minutes = bcdToDec(minutes); // convert BCD to decimal
    hours   = (((hours   & 0B00110000)>>4)*10 + (hours & 0B00001111)); // convert BCD to decimal (assume 24 hour mode)
    day     = (day & 0B00000111); // 1-7
    date    = (((date & 0B00110000)>>4)*10 + (date & 0B00001111)); // 1-31
    month   = (((month & 0B00010000)>>4)*10 + (month & 0B00001111)); //msb7 is century overflow
    year    = (((year & 0B11110000)>>4)*10 + (year & 0B00001111));
    */
  }
  else {
    //oh noes, no data!
  }
 /*
  switch (day) {
    case 1:
      strcpy(weekDay, "Sun");
      break;
    case 2:
      strcpy(weekDay, "Mon");
      break;
    case 3:
      strcpy(weekDay, "Tue");
      break;
    case 4:
      strcpy(weekDay, "Wed");
      break;
    case 5:
      strcpy(weekDay, "Thu");
      break;
    case 6:
      strcpy(weekDay, "Fri");
      break;
    case 7:
      strcpy(weekDay, "Sat");
      break;
  }
  */
}
