#include "watchX.h"

//#include <nano_gfx.h>

  #include "usb.h"
#include "battery.h"




extern unsigned char DEVICESTATE;


void drawUsb( ){



//uint8_t buf[32*2];

      //NanoCanvas c(24,8,buf);
        if(DEVICESTATE&128){
           //c.drawBitmap(2, 0, 16,8, usbIcon);






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
