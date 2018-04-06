
//#include <nano_gfx.h>

  #include "usb.h"
#include "battery.h"
#include "oled.h"
#include "resources.h"




void drawUsb(  ){



//uint8_t buf[32*2];

      //NanoCanvas c(24,8,buf);
        if(DEVICESTATE&128){
        //   draw_bitmap(40, 0, watchXui,8,8,false,0);
//if(digitalRead(CHARGE_PIN)==LOW&& batterylevel<630)
draw_bitmap( 36, 56, watchXui+64, 8, 8, false, 0);
//
draw_bitmap(18, 56, watchXui+80,16,8,false,0);

//

    }


//  sprite = ssd1306_createSprite( 112, 56, 16, usbIcon );

  /* Draw sprite on the display */
//  sprite.draw();


}
