#include "watchX.h"
#include <EEPROM.h>
#include "bluetooth.h"
#include "oled.h"
#include "rtc.h"
/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
Adafruit_BluefruitLE_SPI ble(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);


void ble_sw1(){
  if((~SW1_WASPUSHED)&SW1_PUSHED){
    gotoWatchFace();
    }
  }
  const char months[12][BUFFSIZE_STR_MONTHS] PROGMEM = {
    "JAN",
    "FEB",
    "MAR",
    "APR",
    "MAY",
    "JUN",
    "JUL",
    "AUG",
    "SEP",
    "OCT",
    "NOV",
    "DEC"
  };


  const char days[7][BUFFSIZE_STR_DAYS] PROGMEM = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN"
  };

  void handleBle( ){
unsigned char cmd,i;
//if(!ble)return;
if(ble.available()){


cmd=ble.read();
        switch(cmd){
          case 0:
          for(uint8_t i=0;i<7;i++)
          curtm[i]=ble.read();
          /*
          curtm[1]=ble.read();
          curtm[2]=ble.read();
          curtm[3]=ble.read();
          curtm[4]=ble.read();
          curtm[5]=ble.read();
          curtm[6]=ble.read();
          */
          setDateTime();
      //    getDateTime(); //// we need to reread for true bcd conversion...
          break;
          case 1:
          digitalWrite(13,HIGH);
            while(ble.available())ble.read();
          break;
          case 2:
          digitalWrite(13,LOW);
            while(ble.available())ble.read();
          break;
          case 3:
          ble.setMode(BLUEFRUIT_MODE_DATA);
          ble.write((uint8_t*)curtm,7);
          ble.waitForOK();
/*
          Serial.println(curtm[0]);
          Serial.println(curtm[1]);
          Serial.println(curtm[2]);
          Serial.println(curtm[3]);
          Serial.println(curtm[4]);
          Serial.println(curtm[5]);
          Serial.println(curtm[6]);

*/
            break;

            case 4:

            i=0;
                 while ( ble.available() ){

                   strtmpbuf[i]=ble.read();
                        i++;
                 }





                 strtmpbuf[i]=0;
                 ble.setMode(BLUEFRUIT_MODE_COMMAND);

                 ble.print( "AT+GAPDEVNAME=" );
                  ble.print(strtmpbuf);
                 ble.println();
                 ble.waitForOK();
                      ble.setMode(BLUEFRUIT_MODE_DATA);
            break;
            case 5:
                // [5,aa.getSeconds(),aa.getMinutes(),aa.getHours(), aa.getDay(),aa.getDate(),aa.getMonth(),aa.getYear()-100]
                i=0;
                while(ble.available()){
                  curtm[i] = ble.read();
                  setDateTime();
                  i++;
                }
            break;

          case ' ':
          i=0;

          while ( ble.available() ){
            EEPROM.write(100+i, ble.read());
            delay(5);
           // strtmpbuf[i]=ble.read();
                 i++;
          }

          EEPROM.write(99+i,0); /// end of sms message text


        gotoBlueTooth( );
          break;

          default:
            while(ble.available()){
            //  Serial.write(ble.read());
            ble.read();
            }
          break;
        }
      //

}
    }
    const char title[] PROGMEM="< INCOMING MESSAGE >";
    void drawBle(){

        drawString_P(4,0,title,smallFont);
        drawString_E(0,8, 100,smallFont);
      //  drawString(0,8,strtmpbuf,smallFont);

      }
     // int timepassed=0;
void ble_connect(){

      //if(!ble)ble =new Adafruit_BluefruitLE_SPI(BLUEFRUIT_SPI_CS, BLUEFRUIT_SPI_IRQ, BLUEFRUIT_SPI_RST);
     if ( !ble.begin(false) )
      {
       //error(F("Couldn't find Bluefruit, make sure it's in CoMmanD mode & check wiring?"));
      }


  //    ble.echo(false);
  //    ble.verbose(false);  // debug info is a little annoying after this point!
  /*
        if ( FACTORYRESET_ENABLE )
      {
        if ( ! ble.factoryReset() ){
         // error(F("Couldn't factory reset"));
        }
      }

    Disable command echo from Bluefruit */


      /* Wait for connection */
     // while (! ble.isConnected()) {
      //    delay(500);
     // }

      // Set module to DATA mode
      ble.setMode(BLUEFRUIT_MODE_DATA);


  }
