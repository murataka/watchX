#include "watchX.h"
#include "diag.h"
#include "oled.h"
#include "temperature.h"
#include "watchXmpu6050.h"

void drawDiag(){

  drawString(16,0,"< DIAGNOSTICS >",smallFont);

char strbuf[10]={temperature/10+48,((int)temperature%10)+48,0};

  drawString(0,8,strbuf,smallFont);

    strbuf[0]=((((unsigned long)(mpu.readRawAccel().XAxis/100)%100)/10)%10)+48;
     strbuf[1]=((unsigned long)(mpu.readRawAccel().XAxis/100)%10)+48 ;
     strbuf[2]=0;
if(mpu.readRawAccel().XAxis!=0)
  drawString(0,16,strbuf,smallFont);
  


}
