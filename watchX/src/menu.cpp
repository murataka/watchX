#include "menu.h"
#include <Arduino.h>
//#include <ssd1306.h>
//#include <nano_gfx.h>

#include "watchX.h"
#include "stopwatch.h"
#include "diag.h"
#include "oled.h"
// #include "intf/ssd1306_interface.h"


      int _x=0;
int speed=0;
int scrollto=0;


//unsigned char menupos[5]={-48,0,48,96,144};
  int menuindex=0;


void menusw1( ){
  if((~SW1_WASPUSHED)&SW1_PUSHED){
    switch(menuindex){
      case MENU_EXIT:
    // ssd1306_clearScreen();
  gotoWatchFace();

      break;
      case MENU_STOPWATCH:
gotoStopWatch();


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
/*
uint8_t * menus[MENU_LENGTH]={menu_alarm,menu_torch,menu_stopwatch,menu_settings,menu_games,menu_sound,menu_exit,NULL};
    int menuindex=0;
void menusw1(unsigned long microseconds,unsigned long miliseconds,unsigned long seconds ,unsigned long minutes,unsigned long hours){
     if((~SW1_WASPUSHED)&SW1_PUSHED){
        if(menus[(((menuindex+1) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]==NULL){
    //          scrollto=6;
    //            speed=-8;
        }

        else
        {
          if(speed==0){
            scrollto=menuindex+1;
          speed=16;
          }


        }

          //    scrollto=(((menuindex+1) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH ;
          //  speed=8;

///if(menuindex==3)menuindex=0; /// todo : menucount
}


}

void menusw3(unsigned long microseconds,unsigned long miliseconds,unsigned long seconds ,unsigned long minutes,unsigned long hours){
     if((~SW3_WASPUSHED)&SW3_PUSHED){
       if(menus[(((menuindex+3) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]==NULL){
    //      scrollto=-1;
    //        speed=8;
       }

       else{
             if(speed==0){
         scrollto=menuindex+1;
               speed=-16;
             }
       }
//       scrollto=(((menuindex-1) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH ;
//     speed=-8;


///if(menuindex==3)menuindex=0; /// todo : menucount
}
}
int getSelectedMenu(){
    for(int i=0;i<MENU_LENGTH;i++)
    {
      if(menus[(((menuindex) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]==menus[i])
      return i;
    }
  return -1;
}

void menusw2(unsigned long microseconds,unsigned long miliseconds,unsigned long seconds ,unsigned long minutes,unsigned long hours){

     if((~SW2_WASPUSHED)&SW2_PUSHED){
       switch(getSelectedMenu()){
         case 4:
        ssd1306_clearScreen();
       uiFunc=printWatchFace;
        sw1Func=gotoMenu;
         sw2Func=NULL;
         sw3Func=NULL;

         break;
         case 0:

  //       uiFunc=drawStopwatch;
    //     sw1Func=gotoMenu;
    //     sw2Func=gotoMenu;
    //     sw3Func=NULL;

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

*/
void drawMenus(){

memset(mbuf, 0x00, 128*8);

for(   char a=-1;a<4;a++)
//  c2.drawBitmap(_x+(a*48),0,32,32,menus_bits+((menuindex+a+1)*4*32) );
if(menuindex+a-1>=0)  draw_bitmap(_x+(a*48) , 16, menus_bits+((menuindex+a-1)*4*32), 32, 32, false, 0);

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

/*
void drawMenu(unsigned long microseconds,unsigned long miliseconds,unsigned long seconds ,unsigned long minutes,unsigned long hours){
  //  canvas.printFixed(0, 0, "USB" );

  unsigned char buf2[128*56/8];
  NanoCanvas c2(128,56,buf2);

    c2.drawBitmap (46, 14,36,8, selectbar_top);
	  c2.drawBitmap (46, 42,36,8, selectbar_bottom);
  c2.charF6x8(32,0,"<Main Menu>");
//menuindex=_x/48;
if(menus[((menuindex %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH ]!=NULL){
  c2.drawBitmap ((_x+menupos[0]),16,32,32,menus[((menuindex %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH ] );
}
if(menus[(((menuindex+1) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]!=NULL){
  c2.drawBitmap ((_x+menupos[1 ]),16,32,32,menus[(((menuindex+1) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]);   //// torch is lower?
}
if(menus[(((menuindex+2) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]!=NULL){
  c2.drawBitmap ((_x+menupos[2 ]),16,32,32,menus[(((menuindex+2) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]);
}
if(menus[(((menuindex+3) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]!=NULL){
  c2.drawBitmap ((_x+menupos[3 ]),16,32,32,menus[(((menuindex+3) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]);
}
if(menus[(((menuindex+4) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]!=NULL){
  c2.drawBitmap ((_x+menupos[4]),16,32,32,menus[(((menuindex+4) %MENU_LENGTH) +MENU_LENGTH )%MENU_LENGTH]);
}



//AC1091410022604
//if(menuindex+3<3)
//drawSprite(_x+menupos[(menuindex+3)  ],16,32,32,menu_default);


_x+=speed;

//if(_x>=48*MENU_LENGTH||_x<=0)
//speed*=-1;
if(_x==32) speed=speed/4;

if(_x==-32) speed=speed/4;

if(_x==48){
menuindex--;

}
if(_x==-48){
menuindex++;

}


if(_x==48||_x==-48 ){
  speed=0;
  _x=0;
}


c2.blt(0,0);
}
*/
