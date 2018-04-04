#ifndef WATCHX_H
#define WATCHX_H

#include <Arduino.h>
#include "batteryui.h"
#include "watchface.h"
#include "menu.h"
#include "temperature.h"
#include "watchXmpu6050.h"
#define SW1 8
#define SW2 11
#define SW3 10

#define LED1 13
#define LED2 6
#define BUZZER_PIN 9





extern MPU6050 mpu;

extern volatile uint8_t animating;
extern volatile unsigned long lastcolon;

// Scrolling #defines


///// 4 : low -> charging
///// 4 : high -> charged
//// clock 3231 rtclib
//// buzzer -> 9
////// led -> 13 , 6
/// gyro 0x69 , int:7 pin, int6
//// bluetooth , oled
//magnetometre , pressure , i2c


#define PIN_INTERRUPT   PD1 // interrupt pin

extern unsigned char DEVICESTATE;
extern unsigned char Old_DEVICESTATE;




//extern char strtmpbuf[];
//extern   unsigned char buf[128*64/8];
//extern  NanoCanvas c;

enum CMD{END=0,TEXT,BITMAP,LINE,STATE,ANIMATE,RECT};
enum STATES{PROGRESS=0,DONE};
enum ANIMATIONS{LINEARX=0,LINEARY,SWINGX,SWINGY};

enum WATCHKEYS{PREVKEY=10,NEXTKEY=11,SELECTKEY=8};

typedef void (*func_type)(    );


#define USBDEVICE UDADDR & _BV(ADDEN)



#define BATTERY_PIN  A11


#define BATTERY_EN  4
//#define LED = 6;

#define SW1_PUSHED DEVICESTATE&1
#define SW2_PUSHED DEVICESTATE&2
#define SW3_PUSHED DEVICESTATE&4
#define SW1_WASPUSHED Old_DEVICESTATE&1
#define SW2_WASPUSHED Old_DEVICESTATE&2
#define SW3_WASPUSHED Old_DEVICESTATE&4
#define SECOND_CHANGED DEVICESTATE&8
#define SECOND_WASCHANGED Old_DEVICESTATE&8

#define HANDLEDFUNCTIONS_COUNT 5
#define usbFunc 0
#define sw1Func 7
#define sw2Func 6
#define sw3Func 5
#define uiFunc 4
#define batteryFunc 2
#define bleFunc 1
#define updateFunc 3

extern unsigned char DEVICESTATE;
//extern char *activekeyframe;
extern char strtmpbuf[];
extern unsigned char mbuf[128*8];
extern func_type nextUIFunc;

//extern func_type usbFunc ,sw1Func,sw2Func,sw3Func,uiFunc,batteryFunc,bleFunc;
extern func_type functions[];
void handleFunction(func_type f);

void gotoMenu(  );
 
void gotoWatchFace( );
void gotoGyroFace( );
void gotoDiagnostic();
void gotoStopWatch( );
void gotoBlueTooth( );
void gotoSettings( );





#endif
