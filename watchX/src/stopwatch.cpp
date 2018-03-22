#include "watchX.h"
#include "stopwatch.h"
#include <oled.h>




//extern   unsigned char buf[128*64/8];
//extern  NanoCanvas c;
extern unsigned char DEVICESTATE;




void drawStopwatch( ){
unsigned char date,year,seconds,minutes,hours;
clearAll();


    draw_bitmap( 0, 16, font_mid+((hours/10)*57), 19, 24, false, 0);
    draw_bitmap( 20, 16, font_mid+((hours%10)*57), 19, 24, false, 0);

    draw_bitmap( 56, 16, font_mid+((minutes/10)*57), 19, 24, false, 0);
    draw_bitmap( 76, 16, font_mid+((minutes/10)*57), 19, 24, false, 0);

    draw_bitmap( 104, 24, small2Font+((seconds/10)*22), 11, 16, false, 0);

  //  draw_bitmap( 117, 24-((animating&&(lastcolon<300))?(lastcolon/10):0), small2Font+(((animating?seconds:seconds)%10)*22), 11, 16, false, 0);
  //  draw_bitmap( 117, 48-((animating&&(lastcolon<300))?(lastcolon/10):0), small2Font+(((animating?seconds+1:seconds)%10)*22), 11, 16, false, 0);


    draw_bitmap( 117, 24-(lastcolon*48/255), small2Font+(((seconds)%10)*22), 11, 16, false, 0);
    draw_bitmap( 117, 48-lastcolon*48/255, small2Font+(((seconds+1)%10)*22), 11,  16, false, 0);


    draw_bitmap( 117, 24-(lastcolon*48/255), small2Font+(((seconds)%10)*22), 11, 16, false, 0);
    draw_bitmap( 117, 48-lastcolon*48/255, small2Font+(((seconds+1)%10)*22), 11,  16, false, 0);


  //if(lastcolon>249)


   //    c.drawBitmap(22,16,19,24,font_mid+((hours%10)*57));////30 byte //// 19 *3


      draw_bitmap(0,0,lastcolon<=128?0xff:0B11001111,1,8,false,0);

  // c.drawBitmap(62,16,19,24,font_mid+((minutes/10)*57));
    //   c.drawBitmap(84,16,19,24,font_mid+((minutes%10)*57));////30 byte

    //   c.drawBitmap(105,24,11,16,small2Font+((seconds/10)*22));
    //   c.drawBitmap(117,24,11,16,small2Font+((seconds%10)*22));////30 byte


    //  c.blt(0,0);


        if(lastcolon<=128){
           lastcolon++;

        }


/*
 uint8_t buf[128*7];
     NanoCanvas c(128,56,buf);
//  c.charF12x16(10, 10, "00:00", STYLE_BOLD);
//c.printFixedN(10,10,"00:00" ,STYLE_NORMAL, FONT_SIZE_8X);

//c.drawBitmap(112, 56, 16,8, usbIcon);

c.drawBitmap(1, 20,MIDFONT_WIDTH, MIDFONT_HEIGHT, midFont[0]);

c.drawBitmap(24, 20,MIDFONT_WIDTH, MIDFONT_HEIGHT, midFont[0]);

c.drawBitmap(60, 20,MIDFONT_WIDTH, MIDFONT_HEIGHT, midFont[0]);

c.drawBitmap(83, 20,MIDFONT_WIDTH, MIDFONT_HEIGHT, midFont[0]);

//c.drawBitmap(49, 20 , FONT_COLON_WIDTH, FONT_COLON_HEIGHT,  colon);

c.drawBitmap(104, 28,FONT_SMALL2_WIDTH, FONT_SMALL2_HEIGHT, small2Font[0]);

c.drawBitmap(116, 28,FONT_SMALL2_WIDTH, FONT_SMALL2_HEIGHT, small2Font[0]);


c.blt(0,0);
*/
}
