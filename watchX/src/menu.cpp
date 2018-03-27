#include "menu.h"
#include <Arduino.h>


#include "watchX.h"
#include "stopwatch.h"
#include "diag.h"
#include "oled.h"
#include "gyrocube.h"

      int _x=0;
int speed=0;
int scrollto=0;


  int menuindex=0;


void menusw1( ){
  if((~SW1_WASPUSHED)&SW1_PUSHED){
    switch(menuindex){
      case MENU_WATCH:
    // ssd1306_clearScreen();
  gotoWatchFace();

      break;
      case MENU_STOPWATCH:
gotoStopWatch();


      break;
      case MENU_GYROCUBE:
        gotoGyroFace();

      break;

      case 6:
 //     uiFunc=drawDiag;
 //     sw1Func=gotoMenu;
 //     sw2Func=gotoMenu;
 //     sw3Func=NULL;
//       batteryFunc=NULL;
//       usbFunc=NULL;
      break;

      default:
   //   itoa(getSelectedMenu(),strtmpbuf,10);
     //      c2.charF6x8(32,56,strtmpbuf);
      break;

    }
}
}



void menusw2( ){
     if((~SW2_WASPUSHED)&SW2_PUSHED){

      speed=-1;

     }
}
void menusw3( ){
     if((~SW3_WASPUSHED)&SW3_PUSHED){
     if(menuindex>0){
        speed=1;
     }
     }
}

void drawMenus(){

memset(mbuf, 0x00, 128*8);
drawLine(48,12,80,12);

  drawLine(48,12,45,speed==0?15:12);
  drawLine(80,12,83,speed==0?15:12);

  drawLine(48,52,45,speed==0?49:52);
  drawLine(80,52,83,speed==0?49:52);
drawLine(48,52,80,52);

for(   char a=-1;a<4;a++)
//  c2.drawBitmap(_x+(a*48),0,32,32,menus_bits+((menuindex+a+1)*4*32) );



if(menuindex+a-1>=0){
  if(menuindex==MENU_GYROCUBE&&speed==0)
  gyroCube(8);

if(menuindex!=MENU_GYROCUBE|| menuindex+a-1!=MENU_GYROCUBE||speed!=0)
  draw_bitmap(_x+(a*48) , 16, menus_bits+((menuindex+a-1)*4*32), 32, 32, false, 0);
}

_x+=speed;
 if(_x==48){
  speed=0;
   _x=0;
  menuindex--;
  }
  if(_x==-48){
  speed=0;
  _x=0;
  menuindex++;
  }

}
