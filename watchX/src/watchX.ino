#define IR_USE_TIMER1


#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
//#include <TimeLib.h>
#include "watchX.h"
#include "oled.h"
#include "cpu.h"
#include "timerone.h"
#include "buzzer.h"
#include "gyroaccel.h"
#include "gyrocube.h"
#include "mag3110.h"
#include "pressure.h"

#include "resources.h"
#include "usb.h"
#include "watchface.h"
#include "stopwatch.h"
#include "menu.h"
#include "battery.h"
#include "diag.h"
#include "altitude.h"
#include "pressure.h"
#include "temperature.h"
#include "rtc.h"
#include <Tones.h>
#include "soundfx.h"
#include "menu.h"

#include "bluetooth.h"





//BMP280 bmp280;
volatile uint8_t animating=1;
 unsigned char mbuf[128*8];
extern volatile uint8_t animating;
volatile unsigned long lastcolon;
char strtmpbuf[50];

//extern volatile unsigned long lastcolon;
func_type functions[HANDLEDFUNCTIONS_COUNT];

func_type nextUIFunc=NULL;

//MPU6050 accelgyro(0x69);

//func_type usbFunc =NULL,sw1Func=NULL,sw2Func=NULL,sw3Func=NULL,uiFunc=NULL;
unsigned char DEVICESTATE=0;
unsigned char Old_DEVICESTATE=DEVICESTATE;


//func_type usbFunc =NULL,sw1Func=NULL,sw2Func=NULL,sw3Func=NULL,uiFunc=NULL,batteryFunc=NULL,bleFunc=NULL;


void nextSecond(/* arguments */) {

//if(lastcolon>=160){



//}
if(!animating) lastcolon=0;
  animating=!animating;
curtm[0]+=animating;
if(animating){
  if(curtm[0]==59){

     curtm[0]=0;

     curtm[1]++;
          if(curtm[1]==59){
              curtm[1]=0;
              curtm[2]++;

          }

  }
}

//lastcolon=0;
///secondsofday+=animating;


}






void updateThings( ){
//get3231Date();
//  dt =Rtc.GetDateTime();// RtcDateTime(__DATE__, __TIME__);

//  if(seconds==0) {   /// TODO change batteryread to something more global


  if(millis()-batteryread>1000){
    batterylevel=readBattery(BATTERY_EN,BATTERY_PIN);
if(batterylevel<530){

}else{
  MPU6050_update();
  getPressure();
}



  batteryread=millis();

    }
  //}
}
void gotoMenu( ){
//if(menuindex<2)
//menuindex=1;
       if(functions[uiFunc]==NULL|| (~SW1_WASPUSHED)&SW1_PUSHED){
//    ssd1306_clearScreen();
        //  usbFunc= drawUsb;
      ///  nextUIFunc=functions[ uiFunc];
      nextUIFunc= drawMenus;
         functions[sw1Func]=menusw1;
         functions[sw2Func]=menusw2;
          functions[sw3Func]=menusw3;
        //  speed=0;
          functions[batteryFunc]=NULL;
        //  batteryFunc=drawBattery;
      functions[usbFunc]=NULL;
         // Old_DEVICESTATE=DEVICESTATE; /// TODO DEFINE ACTIONCOMPLETE


        }
}



void gotoWatchFace(){
           if(functions[uiFunc]==NULL||(~SW1_WASPUSHED)&SW1_PUSHED){
        nextUIFunc= drawWatchFace;//printWatchFace;//printWatchFace;// drawWatchFace;// printWatchFace;
          functions[sw1Func]=gotoMenu;
          functions[sw2Func]=NULL;
          functions[sw3Func]=NULL;
        //  functions[ uiFunc];
            //  nextUIFunc=functions[ uiFunc];
        //  speed=4;
        //  sw2Func=gotoMenu;
        //  sw3Func=NULL;
      functions[  bleFunc] =handleBle;
         functions[usbFunc]=drawUsb;
      functions[batteryFunc]=drawBattery;
      functions[updateFunc]=updateThings;
      }
  }
  void gotoGyroFace(){
       if(functions[uiFunc]==NULL||(~SW1_WASPUSHED)&SW1_PUSHED){
          nextUIFunc= drawGyroCube;//printWatchFace;//printWatchFace;// drawWatchFace;// printWatchFace;
            functions[sw1Func]=gotoMenu;
            functions[sw2Func]=NULL;
            functions[sw3Func]=NULL;
            //    nextUIFunc=functions[ uiFunc];
          //  sw2Func=gotoMenu;
          //  sw3Func=NULL;
        functions[  bleFunc] =handleBle;
           functions[usbFunc]=drawUsb;
        functions[batteryFunc]=drawBattery;
        functions[updateFunc]=updateThings;
      }
    }
void gotoStopWatch(){
           if(functions[uiFunc]==NULL||(~SW1_WASPUSHED)&SW1_PUSHED){
              nextUIFunc=drawStopwatch;
              functions[sw1Func]=gotoMenu;
              functions[sw2Func]=NULL;
              functions[sw3Func]=NULL;
      }
}
void gotoBlueTooth(){
           if(functions[uiFunc]==NULL||(~SW1_WASPUSHED)&SW1_PUSHED){
              nextUIFunc=drawBle;
              functions[sw1Func]=gotoMenu;
              functions[sw2Func]=NULL;
              functions[sw3Func]=NULL;
      }
}

void gotoDiagnostic(){
           if(functions[uiFunc]==NULL||(~SW1_WASPUSHED)&SW1_PUSHED){
              nextUIFunc=drawDiag;
              functions[sw1Func]=gotoMenu;
              functions[sw2Func]=NULL;
              functions[sw3Func]=NULL;
      }
}





const uint8_t melody[]={NOTE_B0};


void setup()
{

soundenabled=true;
sound.tone(1200, 100,1000, 50,1800, 200);
setPrescale();

//timerOneFunc=timerOneTones;
          /* Set timer1 interrupt to 20Hz */
  //  startTimerOne();

     SPI.begin();



//Serial.begin(115200);
pinMode(rstPin, OUTPUT);
pinMode(CHARGE_PIN,INPUT);
pinMode(LED1, OUTPUT);
pinMode(LED2, OUTPUT);

    pinMode(cesPin, OUTPUT);
    pinMode(dcPin, OUTPUT);

digitalWrite(rstPin, HIGH);

  digitalWrite(rstPin, HIGH);
  digitalWrite(dcPin, HIGH);
  digitalWrite(cesPin, HIGH);

//wdt_enable (WDTO_250MS);
 // wdt_disable();

//wdt_enable(WDTO_2S);


     Wire.begin();
    //ssd1306_sendCommand(SSD1306_SEGREMAP | 0x2);
    /* Set range of the SpritePool field on the screen in blocks. *
     * Use whole LCD display                                      *
     * 0,0   means left-top block of lcd display.                 *
     *                         that is 0*8=0 - pixel              *
     *                                 0*8=0 - pixel              *
     * 15,7  means right-bottom block of lcd:                     *
     *                         that is 15*8+7=127-th pixel        *
     *                                 7*8+7=63-rd pixel          */
//setDateTime();

pinMode(13,OUTPUT);

   pinMode(BATTERY_EN, OUTPUT);
  digitalWrite(BATTERY_EN,LOW);

         pinMode(PIN_INTERRUPT, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(PIN_INTERRUPT), nextSecond, CHANGE);


MPU6050_begin();
MAG3110_begin();

//   mpu6050.calcGyroOffsets(true);


startSqw(); /// Starts 1 second SquareWave from DS3231


get3231Temp();
setDateTime();

     pinMode(SW1,INPUT_PULLUP);
       pinMode(SW2,INPUT_PULLUP);
       pinMode(SW3,INPUT_PULLUP);




    ssd1306_configure();

//goto
functions[uiFunc]=drawWatchFace;
     gotoWatchFace();
  //  ble_connect(); // TODO: bluetoot enable / disable 
updateThings();

}
//uint8_t buffer[64*128/8];

void drawLoop( ){

clearAll();
/*
 if(nextUIFunc!=NULL&&nextUIFunc!=functions[uiFunc]){

//     ssd1306_sendCommand(SSD1306_SETSTARTLINE | (animPos) % 64);
  //   handleFunction(functions[uiFunc]);
animation_offsetY++;
     if(animation_offsetY>=64){
      animation_offsetY=0;
      functions[uiFunc]=nextUIFunc;
 //nextUIFunc=NULL;
      }

 }else{
//animation_offsetY=0;

//

 }
 //while(1);

if(animation_offsetY==0)
*/
for(int a=0;a<HANDLEDFUNCTIONS_COUNT;a++)
handleFunction(functions[a]);

 ssd1306_drawBuffer(0, 0, 128,64, mbuf);
}



void loop()
{

//if(micros()-lastdraw>16000){ ///// 60 frames per second
//digitalWrite(13,(secondsofday%2)==0?LOW:HIGH);
    //   ssd1306_sendCommand(SSD1306_SETSTARTLINE|16);
                // 0xD3
   // ssd1306_sendCommand(animPos);                                   // no offset
//    animPos++;
digitalWrite(LED2,sound.playing()?HIGH: LOW);

   DEVICESTATE=(USBDEVICE )|((digitalRead(SW1)==LOW))|((digitalRead(SW2)==LOW)<<1)|((digitalRead(SW3)==LOW)<<2);
     drawLoop();
              if(DEVICESTATE!=Old_DEVICESTATE){
            //      ssd1306_fillScreen(0x00);
            //  interact();
if(DEVICESTATE&0B00000111){
  buttonFX(1200);

}


                  Old_DEVICESTATE=DEVICESTATE;
                }
   // DEVICESTATE=(USBDEVICE )|((digitalRead(SW1)==LOW))|((digitalRead(SW2)==LOW)<<1)|((digitalRead(SW3)==LOW)<<2);
 //  lastdraw=micros();

//}
/*
if(millis()-lastinteract>100){


              if(DEVICESTATE!=Old_DEVICESTATE){
            //      ssd1306_fillScreen(0x00);
            //  interact();
                  Old_DEVICESTATE=DEVICESTATE;
                }

   lastinteract=millis();
}

if(millis()-lastsecond>1000){

//   fps=framecount;
  // framecount=0;
//    interact();
 //  lastsecond=millis();
  }
*/




}

void handleFunction(func_type f){
  if(f!=NULL)f( );

}
