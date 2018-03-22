#include "watchX.h"
#include "watchface.h"
#include "rtc.h"
#include "oled.h"
//#include <nano_gfx.h>



extern unsigned char DEVICESTATE;
//uint8_t buf2[16*2];






//unsigned int i=0;

void printWatchFace( ){
 //char strtmpbuf[10];
memset(mbuf, 0x00, 128*8);
 // uint8_t buf[128*5];
//    NanoCanvas c(128,40,buf);


 for(int a=0;a<3;a++){
      //strtmpbuf[a]= ;
      draw_bitmap( 16+ (a*6), 0, smallFont[pgm_read_byte_near(days[day]+a)-32], 5, 8, false, 0);
       draw_bitmap( 60+ (a*6), 0, smallFont[pgm_read_byte_near(months[month]+a)-32], 5, 8, false, 0);



    }

  //  strtmpbuf[3]=0;
//    c.charF6x8(16, 0,strtmpbuf);



    ///////////////
   // ltoa(date,strtmpbuf,10);
    //if(date<10) //c.charF6x8(42, 0,"0");
       draw_bitmap( 42, 0, smallFont[(date/10)+16], 5, 8, false, 0);


         draw_bitmap( 48, 0, smallFont[(date%10)+16], 5, 8, false, 0);

  //  c.charF6x8(48, 0,strtmpbuf);


    //////////////
    {
    char b[4]={2,0,0,0};
    b[2]=year/10;
    b[3]=year%10;

    for(char a=0;a<4;a++){
    //  strtmpbuf[a]= pgm_read_byte_near(months[month]+a);
  //  draw_bitmap( 0, 32, font_mid, 19, 24, false, 0);

       draw_bitmap( 86+(a*6), 0, smallFont[b[a]+16], 5, 8, false, 0);
    }
  }
  //  strtmpbuf[3]=0;
   // c.charF6x8(60, 0,strtmpbuf);

    //////////////


 //   ltoa(year+2000,strtmpbuf,10);


  //  c.charF6x8(84, 0,strtmpbuf);



  draw_bitmap( 0, 16, font_mid+((hours/10)*57), 19, 24, false, 0);
  draw_bitmap( 20, 16, font_mid+((hours%10)*57), 19, 24, false, 0);

  draw_bitmap( 56, 16, font_mid+((minutes/10)*57), 19, 24, false, 0);
  draw_bitmap( 76, 16, font_mid+((minutes/10)*57), 19, 24, false, 0);

  //draw_bitmap( 104, 24, small2Font+((seconds/10)*22), 11, 16, false, 0);

//  draw_bitmap( 117, 24-((animating&&(lastcolon<300))?(lastcolon/10):0), small2Font+(((animating?seconds:seconds)%10)*22), 11, 16, false, 0);
//  draw_bitmap( 117, 48-((animating&&(lastcolon<300))?(lastcolon/10):0), small2Font+(((animating?seconds+1:seconds)%10)*22), 11, 16, false, 0);
draw_bitmap( 104, 24, small2Font+((seconds/10)*22), 11, 16, false, (lastcolon*48/255));
draw_bitmap( 104, 36-((lastcolon)*24/255), small2Font+(((seconds+1)/10)*22), 11,  16, false,-((128-lastcolon)*24/255));


  draw_bitmap( 117, 24, small2Font+(((seconds)%10)*22), 11, 16, false, (lastcolon*48/255));
  draw_bitmap( 117, 36-((lastcolon)*24/255), small2Font+(((seconds+1)%10)*22), 11,  16, false,-((128-lastcolon)*24/255));
//draw_bitmap( 117, 48-((lastcolon)*32/255), small2Font+(((seconds+1)%10)*22), 11,  16, false,-((128-lastcolon)*32/255));

//  draw_bitmap( 117, 24-(lastcolon*48/255), small2Font+(((seconds)%10)*22), 11, 16, false, 0);
//  draw_bitmap( 117, 48-lastcolon*48/255, small2Font+(((seconds+1)%10)*22), 11,  16, false, 0);

  //  c.fillRect(48,23,52,34,animating?0:0B11001111);

// c.drawBitmap(62,16,19,24,font_mid+((minutes/10)*57));
  //   c.drawBitmap(84,16,19,24,font_mid+((minutes%10)*57));////30 byte

  //   c.drawBitmap(105,24,11,16,small2Font+((seconds/10)*22));
  //   c.drawBitmap(117,24,11,16,small2Font+((seconds%10)*22));////30 byte


  //  c.blt(0,0);


      if(lastcolon<128){
        for(char a=-2;a<2;a++){

    draw_bitmap(48+a,24,COLON,1,8,false,0);

    }
         lastcolon++;

      }

}
/*
void drawWatchFace( ){


  uint8_t buf[128*3];

printHead();
  lastcolon+=miliseconds;
    NanoCanvas c2(128,24,buf);


  if(animating){
    c2.drawBitmap(117, 8-22*lastcolon/300,11, 16, small2Font[(second+59)%10]);
    c2.drawBitmap(117, 28-20*lastcolon/300,11, 16, small2Font[(second)%10]);
  }else{
    c2.drawBitmap(117, 8,11, 16, small2Font[(second)%10]);
  }

    c2.fillRect(96,0,128,7,0); //// hide hack
    if(animating&&(second%10)==0){
      c2.drawBitmap(105, 8-22*lastcolon/300,11, 16, small2Font[((second+59)%60)/10]);
      c2.drawBitmap(105, 30-22*lastcolon/300,11, 16, small2Font[((second)%60)/10]);
  }else{
      c2.drawBitmap(105, 8,11, 16, small2Font[((second)%60)/10]);
  }

  //    if((minute%10)==0){
    c2.fillRect(96,0,128,7,0); //// hide hack

  if(animating&&second==0&&(minute%10)==0){
    c2.drawBitmap(62, 0-24*lastcolon/300,19, 24, midFont[((minute)%60)/10]);
    c2.drawBitmap(62, 24-24*lastcolon/300,19, 24, midFont[((minute+1)%60)/10]);
  }else{
    c2.drawBitmap(62, 0,19, 24, midFont[((minute+1)%60)/10]);


  }

  if(animating&&second==0){
       c2.drawBitmap(84, 0-24*lastcolon/300,19, 24, midFont[((minute))%10]);
        c2.drawBitmap(84, 24-24*lastcolon/300,19, 24, midFont[((minute+1))%10]);
  }else{
    c2.drawBitmap(84, 0,19, 24, midFont[((minute+1))%10]);
  }
  if(animating&&second==0&&minute==59){

        c2.drawBitmap(0, 0-24*lastcolon/300,19, 24, midFont[((hour)%24)/10]);
        c2.drawBitmap(0, 24-24*lastcolon/300,19, 24, midFont[((hour+1)%24)/10]);
  }else{
      c2.drawBitmap(0, 0,19, 24, midFont[((hour+1)%24)/10]);
  }
  if(animating&&(second%10)==9&&minute==59){
        c2.drawBitmap(22, 0-24*lastcolon/300,19, 24, midFont[((hour))%10]);
        c2.drawBitmap(22, 24-24*lastcolon/300,19, 24, midFont[((hour+1))%10]);
  }else{
      c2.drawBitmap(22, 0,19, 24, midFont[((hour+1))%10]);
  }







  if(animating)c2.drawBitmap(49, 0 , FONT_COLON_WIDTH, FONT_COLON_HEIGHT,  colon);
  //memcpy(buf2,buf,128*8);






  c2.blt(0,3);
  //  NanoCanvas sc(64,64,buf);

  //sc.

  //  gfx_drawMonoBitmap(0, 0,FONT_SMALL2_WIDTH, FONT_SMALL2_HEIGHT-4, small2Font[dt.Second()/10]);

  //sc.blt(0,0);
   //c.drawSprite(&sprite);

  //sc.blt(0,0);
  //////////////

  //handleFunction(batteryFunc);
    // draw_bitmap(0, FRAME_HEIGHT - 8, battIcon, 16, 8, NOINVERT, 0);
  //  c.drawBitmap(0, 56, 16,8, battIconHigh);

  //  SPRITE sprite;
    //  canvas.printFixed(0, 0, "USB" );
  //  sprite = ssd1306_createSprite( 112, 56, 16, usbIcon );


  //  sprite.draw();

}
*/
