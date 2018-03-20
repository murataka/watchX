
#include "battery.h"
//#include <nano_gfx.h>




//extern   unsigned char buf[128*64/8];
//extern  NanoCanvas c;
extern unsigned char DEVICESTATE;
 float batterylevel=readBattery();
unsigned long batteryread=0;



void drawBattery( ){
  uint8_t buf2[16];

 /// NanoCanvas c(16,8,buf2);

//  c.drawRect(0,0,14,7);
 // c.fillRect(2,2,2+((batterylevel-3.1)*7),5,255); ////todo: batteryshowfunction
 // c.drawVLine(15,2,5);
//c.blt(0,7);
  //sprintf(strtmpbuf,"%.2f",0.5);
//strcpy(strtmpbuf,"den");
  //c.charF6x8(40,56,strtmpbuf );
}


float readBattery(){
  float val=batterylevel;


    digitalWrite(BATTERY_EN,HIGH);
    delayMicroseconds(200);
    val=analogRead(BATTERY_PIN)*152.83;
     digitalWrite(BATTERY_EN,LOW);
     //batteryread=millis();


   return val;
  }
