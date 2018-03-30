#ifndef BLUETOOTH_H
#define BLUETOOTH_H
#include "watchX.h"
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"
#include "BluefruitConfig.h"
//#include "SSD1306Ascii.h"
//#include "SSD1306AsciiSpi.h"

#define ADAFRUITBLE_REQ A2
#define ADAFRUITBLE_RDY 0     // This should be an interrupt pin, on Uno thats #2 or #3
#define ADAFRUITBLE_RST A1

#define FACTORYRESET_ENABLE 1

#if SOFTWARE_SERIAL_AVAILABLE
  #include <SoftwareSerial.h>
#endif

#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"

void drawBle();
void handleBle(bool fromfunction);
void ble_connect();
void ble_sw1();
/* ...hardware SPI, using SCK/MOSI/MISO hardware SPI pins and then user selected CS/IRQ/RST */
extern Adafruit_BluefruitLE_SPI *ble;

#endif
