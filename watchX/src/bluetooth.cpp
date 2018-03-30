#include "watchX.h"
#include "bluetooth.h"
#include "oled.h"

/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI *ble=NULL;

void ble_sw1(){
  if((~SW1_WASPUSHED)&SW1_PUSHED){
    gotoWatchFace();
    }
  }
void error(const __FlashStringHelper*err){

  }
  unsigned char i;
  void handleBle(){

if(ble->available()){ i=0;

     while ( ble->available() )
        {

         strtmpbuf[i++]=ble->read();


      //     functions[sw1Func]= ble_sw1;
         // Serial.print((char)c);
//digitalWrite(13,HIGH);

        }

       if(i>0){
         strtmpbuf[i-1]=0;
  //      uint8_t buf3[128* 4];
          //digitalWrite(13);
    //    NanoCanvas c(128,32,buf3);
    //      c.charF6x8(0, 0,strtmpbuf);
    //  c.blt(0,0);
        nextUIFunc=drawBle;
       }
}
    }
    void drawBle(){
     /// TODO do we need ?
        drawString(4,0,"< INCOMING MESSAGE >",smallFont);
        drawString(0,8,strtmpbuf,smallFont);

      }
     // int timepassed=0;
void ble_connect(){
  if(!ble)ble =new Adafruit_BluefruitLE_SPI(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
 if ( !ble->begin(VERBOSE_MODE) )
  {
   //error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
  }

/*
    if ( FACTORYRESET_ENABLE )
  {
    if ( ! ble->factoryReset() ){
     // error(F("Couldn't factory reset"));
    }
  }
*/
  /* Disable command echo from Bluefruit */
  ble->echo(false);
  ble->verbose(false);  // debug info is a little annoying after this point!

  /* Wait for connection */
 // while (! ble.isConnected()) {
  //    delay(500);
 // }

  // Set module to DATA mode
  ble->setMode(BLUEFRUIT_MODE_DATA);


  }
