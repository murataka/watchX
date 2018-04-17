
#include <Arduino.h>


#include "watchX.h"
#include "menu.h"
#include "torch.h"
#include "oled.h"
#include "gyrocube.h"
#include "settings.h"

        int _x=0;
int menuspeed=0;
int scrollto=0;
uint8_t menuapp=0;

  int menuindex=0;
int targetmenuindex=0;

void menusw1( ){

switch(menuapp){
  case 0:
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
            case MENU_BLUETOOTH:
               gotoBlueTooth();
            break;
          case MENU_TORCH:
             gotoTorch();

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
  break;

  case 1:
  switch(menuindex){
          case MENU_SETTINGS_EXIT:
        // ssd1306_clearScreen();
          gotoMenu();

          break;
          case MENU_SETTINGS_BLUETOOTH:
          gotoBlueToothSettings();
          break;

        }
  break;
  default:
  break;
}


}



void menusw2( ){
//if(animation_offsetY==0)
if(animation_offsetY==0)
     if(menuindex<MENUCOUNT-1){
        menuspeed=-3;
        targetmenuindex=menuindex+1;
     }else{
       targetmenuindex=0;
       menuspeed=5;
     }

}
void menusw3( ){
if(animation_offsetY==0)
     if(menuindex>0){
         targetmenuindex=menuindex-1;
        menuspeed=3;
     }else{
targetmenuindex=MENUCOUNT-1;
       menuspeed=-5;
     }

}
/*
  When memory is dynamically allocated, the atmega chip cannot allocate memory ...
*/
const char title[][15] PROGMEM= {"< MAIN MENU >","< SETTINGS >"};
const char menuCap[][15] PROGMEM ={"Exit","Stopwatch","Gyrocube","Torch","Messages","Settings","Exit","Date&Time","Bluetooth","Screen","Settings3","Settings4","Settings5","Settings6","Settings7","Settings8"};
void drawMenus(){
///char menuCap[][15]={"Exit","Stopwatch","Gyrocube","Diagnostic","Bluetooth","Settings"};
//const char* title PROGMEM= "< MAIN MENU >";

   drawString_P(26,0,title[menuapp],smallFont);
   drawString_P(0,56,menuCap[(menuindex%MENUCOUNT)+(menuapp*MENUCOUNT)],smallFont);

drawLine(48,12,80,12);

  drawLine(48,12,45,menuspeed==0?15:12);
  drawLine(80,12,83,menuspeed==0?15:12);

  drawLine(48,52,45,menuspeed==0?49:52);
  drawLine(80,52,83,menuspeed==0?49:52);
drawLine(48,52,80,52);

for(   char a=-1;a<4;a++)
//  c2.drawBitmap(_x+(a*48),0,32,32,menus_bits+((menuindex+a+1)*4*32) );



if(menuindex+a-1>=0&&menuindex+a-1<MENUCOUNT){
  if(menuindex==MENU_GYROCUBE&&menuspeed==0&&menuapp==0)
 gyroCube(8);

if(menuindex!=MENU_GYROCUBE|| menuindex+a-1!=MENU_GYROCUBE||menuspeed!=0||menuapp==1)

  draw_bitmap(_x+(a*48) , 16, menus_bits+(((menuapp*8)+menuindex+a-1)*4*32), 32, 32, false, 0);
}

_x+=menuspeed;
switch(_x){
case 8:
menuspeed=1;
break;
case -8:
menuspeed=-1;
break;

}
 if(_x>=48){
   if(targetmenuindex==menuindex-1)
  menuspeed=0;
   _x=0;
  menuindex--;
  }
  if(_x<=-48){
     if(targetmenuindex==menuindex+1)
  menuspeed=0;
  _x=0;
  menuindex++;
  }

}
