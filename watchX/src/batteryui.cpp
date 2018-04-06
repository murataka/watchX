#include <Arduino.h>
#include "oled.h"
#include "battery.h"
#include "resources.h"

 void drawBattery(){



draw_bitmap( 0, 56, watchXui+(unsigned)(((batterylevel-500)/40)*16), 16, 8, false, 0);

  
}
