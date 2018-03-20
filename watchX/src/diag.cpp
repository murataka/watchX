#include "watchX.h"
#include "diag.h"

//#include "gyroaccel.h"

//unsigned long last=0;

void drawDiag(){
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

    c.charF6x8(0,8,"Battery" );
sprintf(strtmpbuf, "%5d.%02d", (int)batterylevel, abs((int)(batterylevel*100)%100));
c.charF6x8(68,8,strtmpbuf );
c.charF6x8(116,8,"V" );

c.charF6x8(0,16,"Temperature" );
sprintf(strtmpbuf, "%5d.%02d", (int)temperature, abs((int)(temperature*100)%100));
  c.charF6x8(68,16,strtmpbuf );
c.charF6x8(116,16,"C" );

c.charF6x8(0,24,"Altitude" );
sprintf(strtmpbuf, "%5d.%02d", (int)altitude, abs((int)(altitude*100)%100));
  c.charF6x8(68,24,strtmpbuf );
c.charF6x8(116,24,"m." );

c.charF6x8(0,32,"Pressure" );
sprintf(strtmpbuf, "%5ld.%02ld", (long)pressure, abs((long)(pressure*100)%100));
  c.charF6x8(68,32,strtmpbuf );
c.charF6x8(116,32,"pa" );
c.blt(0,0);
/*
c.charF6x8(0,40,"X1" );
sprintf(strtmpbuf, "%ld",RawValue[0]);
  c.charF6x8(68,40,strtmpbuf );
c.charF6x8(116,40,".." );
*/


}
