#define IR_USE_TIMER1


#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
//#include <TimeLib.h>
#include "watchX.h"
#include "oled.h"
#include "cpu.h"

//#include <sprite_pool.h>

//#include <lcd/ssd1306_commands.h>
//#include <lcd/lcd_common.h>
//#include "intf/ssd1306_interface.h"
// Define which sensors are attached
//#define SENSORS_BMP180_ATTACHED
//#define SENSORS_HMC5883L_ATTACHED
//#include <MPU6050.h>
//#include <Wire.h> // must be included here so that Arduino library object file references work


//char strtmpbuf[10];
//#include <i2c_BMP280.h>

//#include "spi/ssd1306_spi.h"
//#include "spi/ssd1306_spi_hw.h"
//#include "lcd/oled_ssd1306.h"
#include "resources.h"
#include "usb.h"
#include "watchface.h"
#include "menu.h"
#include "battery.h"
#include "diag.h"
#include "altitude.h"
#include "pressure.h"
#include "temperature.h"
#include "rtc.h"
//#include "gyroaccel.h"
//include "bluetooth.h"

//BMP280 bmp280;
volatile uint8_t animating=1;
 unsigned char mbuf[128*8];
extern volatile uint8_t animating;
volatile uint8_t lastcolon;

//extern volatile unsigned long lastcolon;
func_type functions[HANDLEDFUNCTIONS_COUNT];

func_type oldUIFunc=NULL;

//MPU6050 accelgyro(0x69);

//func_type usbFunc =NULL,sw1Func=NULL,sw2Func=NULL,sw3Func=NULL,uiFunc=NULL;
unsigned char DEVICESTATE=0;
unsigned char Old_DEVICESTATE=DEVICESTATE;


//func_type usbFunc =NULL,sw1Func=NULL,sw2Func=NULL,sw3Func=NULL,uiFunc=NULL,batteryFunc=NULL,bleFunc=NULL;


void gotoMenu( ){
  menuindex=0;
       if((~SW1_WASPUSHED)&SW1_PUSHED){
//    ssd1306_clearScreen();
        //  usbFunc= drawUsb;
      //  oldUIFunc=printWatchFace;
         functions[ uiFunc]= drawMenus;
         functions[sw1Func]=menusw1;
         functions[sw2Func]=menusw2;
          functions[sw3Func]=menusw3;
      //    functions[batteryFunc]=NULL;
        //  batteryFunc=drawBattery;
    //     functions[usbFunc]=NULL;
         // Old_DEVICESTATE=DEVICESTATE; /// TODO DEFINE ACTIONCOMPLETE


        }
}




 static const uint8_t PROGMEM s_oled128x64_initData[] =
{
    SSD1306_DISPLAYOFF, // display off
    SSD1306_MEMORYMODE, HORIZONTAL_ADDRESSING_MODE, // Page Addressing mode
    SSD1306_COMSCANDEC,             // Scan from 127 to 0 (Reverse scan)
    SSD1306_SETSTARTLINE | 0x00,    // First line to start scanning from
    SSD1306_SETCONTRAST, 0xFF,      // contast value to 0x7F according to datasheet
    SSD1306_SEGREMAP | 0x01,        // Use reverse mapping. 0x00 - is normal mapping
   SSD1306_NORMALDISPLAY,
    SSD1306_SETMULTIPLEX, 63,       // Reset to default MUX. See datasheet
    SSD1306_SETDISPLAYOFFSET, 0x00, // no offset
    SSD1306_SETDISPLAYCLOCKDIV, 0x80,// set to default ratio/osc frequency
    SSD1306_SETPRECHARGE, 0x22,     // switch precharge to 0x22 // 0xF1
    SSD1306_SETCOMPINS, 0x12,       // set divide ratio
    SSD1306_SETVCOMDETECT, 0x40,    // vcom deselect to 0x20 // 0x40
    SSD1306_CHARGEPUMP, 0x14,       // Enable charge pump
   // 0X20,0X80,
    SSD1306_DISPLAYALLON_RESUME,
    SSD1306_DISPLAYON
};

void updateThings( ){
get3231Date();
//  dt =Rtc.GetDateTime();// RtcDateTime(__DATE__, __TIME__);

//  if(seconds==0) {   /// TODO change batteryread to something more global


  if(millis()-batteryread>1000){
    batterylevel=readBattery(BATTERY_EN,BATTERY_PIN);
    batteryread=millis();

/*
    bmp280.triggerMeasurement();

    bmp280.awaitMeasurement();

    bmp280.getTemperature(temperature);

    bmp280.getAltitude(altitude);  //// TODO altitude update frequency setting ?

    bmp280.getPressure(pressure);
*/
  //  accelgyro.getMotion6(&RawValue[0], &RawValue[1], &RawValue[2],         &RawValue[3], &RawValue[4], &RawValue[5]);



    }
  //}
}

void nextSecond(/* arguments */) {


//   animating=1;

lastcolon=0;
///secondsofday+=animating;


}
void gotoWatchFace(){
  functions[uiFunc]= printWatchFace;//printWatchFace;//printWatchFace;// drawWatchFace;// printWatchFace;
    functions[sw1Func]=gotoMenu;
    functions[sw2Func]=NULL;
    functions[sw3Func]=NULL;
  //  sw2Func=gotoMenu;
  //  sw3Func=NULL;
//functions[  bleFunc] =handleBle;
   functions[usbFunc]=drawUsb;
functions[batteryFunc]=drawBattery;
functions[updateFunc]=updateThings;
  }




/*
void ssd1306_clearScreen()
{
    ssd1306_setBlock(0, 0, 0);
    ssd1306_spiDataStart();
    for(uint8_t m=(s_displayHeight >> 3); m>0; m--)
    {
        for(uint8_t n=s_displayWidth; n>0; n--)
        {
            SPI.transfer(data);
        }
//        ssd1306_nextRamPage();
    }
    ssd1306_spiStop_hw();
}
*/

/*
void ssd1306_drawHLineEx(uint8_t x1, uint8_t y1, uint8_t x2)
{
    ssd1306_setRamBlock(x1, y1 >> 3, x2 - x1 + 1);
    ssd1306_dataStart();
    for (uint8_t x = x1; x <= x2; x++)
    {
        ssd1306_sendPixels((1 << (y1 & 0x07))^s_invertByte);
    }
    ssd1306_endTransmission();
}
*/

ISR(TIMER1_COMPA_vect){
  // pick next note

}

void setup()
{
  //while(!Serial);
    /* Do not init Wire library for Attiny controllers */
setPrescale();

          /* Set timer1 interrupt to 20Hz */
      cli();//stop interrupts
      TCCR1A = 0;// set entire TCCR1A register to 0
      TCCR1B = 0;// same for TCCR1B
      TCNT1  = 0;//initialize counter value to 0
      OCR1A = 781; // approximately 20Hz
      TCCR1B |= (1 << WGM12);// turn on CTC mode
      TCCR1B |= (1 << CS12) | (1 << CS10);  // 1024 presxaler
      TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
      sei();//allow interrupts


     SPI.begin();


//Serial.begin(115200);
pinMode(rstPin, OUTPUT);

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


pinMode(13,OUTPUT);

   pinMode(BATTERY_EN, OUTPUT);
  digitalWrite(BATTERY_EN,LOW);

         pinMode(PIN_INTERRUPT, INPUT_PULLUP);
 attachInterrupt(digitalPinToInterrupt(PIN_INTERRUPT), nextSecond, FALLING);



startSqw(); /// Starts 1 second SquareWave from DS3231


get3231Temp();
get3231Date();

     pinMode(SW1,INPUT_PULLUP);
       pinMode(SW2,INPUT_PULLUP);
       pinMode(SW3,INPUT_PULLUP);





      for( uint8_t i=0; i<sizeof(s_oled128x64_initData); i++)
    {
        ssd1306_sendCommand(pgm_read_byte(&s_oled128x64_initData[i]));
    }


     gotoWatchFace();


}
//uint8_t buffer[64*128/8];

void drawLoop( ){

  for(int a=0;a<HANDLEDFUNCTIONS_COUNT;a++)
 handleFunction(functions[a]);
 if(oldUIFunc!=NULL&&oldUIFunc!=functions[uiFunc]){

//     ssd1306_sendCommand(SSD1306_SETSTARTLINE | (animPos) % 64);
  //   handleFunction(oldUIFunc);
//     animPos++;
     //if(animPos==64){
//      animPos=0;
//      oldUIFunc=NULL;
     // }

 }else{




 }

//handleFunction(drawMenus);

if(DEVICESTATE!=Old_DEVICESTATE){
//      ssd1306_fillScreen(0x00);
//  interact();
//// singlepush handle



    Old_DEVICESTATE=DEVICESTATE;
  }


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
   DEVICESTATE=(USBDEVICE )|((digitalRead(SW1)==LOW))|((digitalRead(SW2)==LOW)<<1)|((digitalRead(SW3)==LOW)<<2);
     drawLoop();
              if(DEVICESTATE!=Old_DEVICESTATE){
            //      ssd1306_fillScreen(0x00);
            //  interact();
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
