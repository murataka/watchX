#include <Arduino.h>
#include "oled.h"
#include "battery.h"
#include "resources.h"
 void drawBattery(){

  // String s;
  // s=batterylevel;
  // drawString(0,48,s.c_str(),smallFont);
<<<<<<< HEAD
//  if(digitalRead(CHARGE_PIN)==LOW)
=======
  if(digitalRead(CHARGE_PIN)==LOW)
>>>>>>> 7491ed92dc86d1f629b90c364edffced25f63699
draw_bitmap( 0, 56, watchXui+(unsigned)(((batterylevel-500)/40)*16), 16, 8, false, 0);

 }
