#include "menu.h"
#include <Arduino.h>


#include "watchX.h"

#include "diag.h"
#include "oled.h"
#include "gyrocube.h"
#include "settings.h"
        int _x=0;
int menuspeed=0;
int scrollto=0;


  int menuindex=0;


void menusw1( ){

    switch(menuindex){
      case MENU_WATCH:
    // ssd1306_clearScreen();
      gotoWatchFace();

      break;
      case MENU_STOPWATCH:
      gotoStopWatch();


      break;
      case MENU_GYROCUBE:
      //  gotoGyroFace();

      break;
        case MENU_BLUETOOTH:
        //    gotoBlueTooth(true);
        break;
      case MENU_DIAGNOSTIC:
        gotoDiagnostic();

      break;
      case MENU_SETTINGS:
        gotoSettings();
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



void menusw2( ){
//if(animation_offsetY==0)
    menuspeed=-2;


}
void menusw3( ){
if(animation_offsetY==0)
     if(menuindex>0){
        menuspeed=2;
     }

}
/*
  When memory is dynamically allocated, the atmega chip cannot allocate memory ...
*/
char menuCap[][15]={"Exit","Stopwatch","Gyrocube","Diagnostic","Bluetooth","Settings"};
void drawMenus(){
///char menuCap[][15]={"Exit","Stopwatch","Gyrocube","Diagnostic","Bluetooth","Settings"};
   drawString(26,0,"< MAIN MENU >",smallFont);
   drawString(0,56,menuCap[menuindex%(sizeof(menuCap)/15)],smallFont);

drawLine(48,12,80,12);

  drawLine(48,12,45,menuspeed==0?15:12);
  drawLine(80,12,83,menuspeed==0?15:12);

  drawLine(48,52,45,menuspeed==0?49:52);
  drawLine(80,52,83,menuspeed==0?49:52);
drawLine(48,52,80,52);

for(   char a=-1;a<4;a++)
//  c2.drawBitmap(_x+(a*48),0,32,32,menus_bits+((menuindex+a+1)*4*32) );



if(menuindex+a-1>=0){
//  if(menuindex==MENU_GYROCUBE&&menuspeed==0)
 //gyroCube(8);

if(menuindex!=MENU_GYROCUBE|| menuindex+a-1!=MENU_GYROCUBE||menuspeed!=0)
  draw_bitmap(_x+(a*48) , 16, menus_bits+((menuindex+a-1)*4*32), 32, 32, false, 0);
}

_x+=menuspeed;
switch(_x){
case 16:
menuspeed=1;
break;
case -16:
menuspeed=-1;
break;

}
 if(_x==48){
  menuspeed=0;
   _x=0;
  menuindex--;
  }
  if(_x==-48){
  menuspeed=0;
  _x=0;
  menuindex++;
  }

}
