#include <Arduino.h>
#include "oled.h"
#include "battery.h"
#include "resources.h"
 void drawBattery(){

  // String s;
  // s=batterylevel;
  // drawString(0,48,s.c_str(),smallFont);
  if(digitalRead(CHARGE_PIN)==LOW)
draw_bitmap( 0, 56, watchXui+(unsigned)(((batterylevel-500)/40)*16), 16, 8, false, 0);

 }
