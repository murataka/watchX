#include "watchX.h"
#include "diag.h"
#include "oled.h"
<<<<<<< HEAD
#include "temperature.h"
#include "watchXmpu6050.h"

void drawDiag(){
=======

//#include "gyroaccel.h"

//unsigned long last=0;

void drawDiag(){

  drawString(16,0,"< DIAGNOSTICS >",smallFont);
/*
if(millis()-last>1000){
  batterylevel=readBattery();
  last=millis();
}
*/
/*
  uint8_t buf[128*8];
NanoCanvas c(128,64,buf);

    c.charF6x8(16,0,"< DIAGNOSTICS >" );
>>>>>>> 7491ed92dc86d1f629b90c364edffced25f63699

  drawString(16,0,"< DIAGNOSTICS >",smallFont);

char strbuf[10]={temperature/10+48,((int)temperature%10)+48,0};

  drawString(0,8,strbuf,smallFont);

    strbuf[0]=((((unsigned long)(mpu.readRawAccel().XAxis/100)%100)/10)%10)+48;
     strbuf[1]=((unsigned long)(mpu.readRawAccel().XAxis/100)%10)+48 ;
     strbuf[2]=0;
if(mpu.readRawAccel().XAxis!=0)
  drawString(0,16,strbuf,smallFont);
  


}
