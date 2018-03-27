
//#include <nano_gfx.h>

  #include "usb.h"
#include "battery.h"
#include "oled.h"
#include "resources.h"


extern unsigned char DEVICESTATE;


void drawUsb(  ){



//uint8_t buf[32*2];

      //NanoCanvas c(24,8,buf);
        if(DEVICESTATE&128){
           //c.drawBitmap(2, 0, 16,8, usbIcon);


           draw_bitmap( 0, 54, watchXui, 16, 8, false, 0);


  draw_bitmap( 18, 54, watchXui+64, 8, 8, false, 0);
        if(batterylevel<4.15f){

            //  uint8_t buf3[8];



        //    c.drawBitmap(18, 0, 8,8, chargeIcon);

}
    }

//c.blt(16,7);

  //sprintf(strtmpbuf, "%d.%02d", (int)batterylevel, abs((int)(batterylevel*100)%100));

//  SPRITE sprite;
  //  canvas.printFixed(0, 0, "USB" );
//  sprite = ssd1306_createSprite( 112, 56, 16, usbIcon );

  /* Draw sprite on the display */
//  sprite.draw();


}
