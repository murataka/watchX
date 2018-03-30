#include "watchX.h"
#include "watchface.h"
#include "rtc.h"
#include "oled.h"
#include "cpu.h"
//#include <nano_gfx.h>


 uint8_t watchMode=0;
extern unsigned char DEVICESTATE;
//uint8_t buf2[16*2];


  int speed;


//unsigned int i=0;

void drawWatchFace(  ){
  const char months[12][BUFFSIZE_STR_MONTHS]  = {
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


  const char days[7][BUFFSIZE_STR_DAYS]  = {
    "MON",
    "TUE",
    "WED",
    "THU",
    "FRI",
    "SAT",
    "SUN"
  };

 //char strtmpbuf[10];

 // uint8_t buf[128*5];
//    NanoCanvas c(128,40,buf);

/*
 for(int a=0;a<3;a++){
      //strtmpbuf[a]= ;
      draw_bitmap( 16+ (a*6), 0, smallFont[pgm_read_byte_near(days[day]+a)-32], 5, 8, false, 0);
       draw_bitmap( 60+ (a*6), 0, smallFont[pgm_read_byte_near(months[month]+a)-32], 5, 8, false, 0);



    }
*/
  //  strtmpbuf[3]=0;
//    c.charF6x8(16, 0,strtmpbuf);



    ///////////////
   // ltoa(date,strtmpbuf,10);
    //if(date<10) //c.charF6x8(42, 0,"0");
    //   draw_bitmap( 42, 0, smallFont[(date/10)+16], 5, 8, false, 0);


      //   draw_bitmap( 48, 0, smallFont[(date%10)+16], 5, 8, false, 0);

  //  c.charF6x8(48, 0,strtmpbuf);


    //////////////
    {
    unsigned char b[16]="    00     2000";
memcpy(b,days[day],3);

memcpy(b+7,months[month],3);

    b[13]+=year/10;
    b[14]+=year%10;
    b[4]+=date/10;
    b[5]+=date%10;

drawString(20,0,b,smallFont);


//drawString(42,0,"30",smallFont);
//    drawString(60,0,months[month],smallFont);

  /*  for(char a=0;a<4;a++){
    //  strtmpbuf[a]= pgm_read_byte_near(months[month]+a);
  //  draw_bitmap( 0, 32, font_mid, 19, 24, false, 0);

       draw_bitmap( 86+(a*6), 0, smallFont[b[a]+16], 5, 8, false, 0);
    }
    */
  }


  //  strtmpbuf[3]=0;
   // c.charF6x8(60, 0,strtmpbuf);

    //////////////


 //   ltoa(year+2000,strtmpbuf,10);


  //  c.charF6x8(84, 0,strtmpbuf);



  draw_bitmap( 0, 24, font_mid+((hours/10)*57), 19, 24, false, 0);
  draw_bitmap( 22, 24, font_mid+((hours%10)*57), 19, 24, false, 0);


  //draw_bitmap( 104, 24, small2Font+((seconds/10)*22), 11, 16, false, 0);

//  draw_bitmap( 117, 24-((animating&&(lastcolon<300))?(lastcolon/10):0), small2Font+(((animating?seconds:seconds)%10)*22), 11, 16, false, 0);
//  draw_bitmap( 117, 48-((animating&&(lastcolon<300))?(lastcolon/10):0), small2Font+(((animating?seconds+1:seconds)%10)*22), 11, 16, false, 0);
/////draw_bitmap( 104, 24, small2Font+((seconds/10)*22), 11, 16, false, (lastcolon*48/255));
/////draw_bitmap( 104, 36-((lastcolon)*24/255), small2Font+(((seconds+1)/10)*22), 11,  16, false,-((128-lastcolon)*24/255));


//  draw_bitmap( 117, 24, small2Font+(((seconds)%10)*22), 11, 16, false, (lastcolon*48/255));
//draw_bitmap( 117, 24, small2Font+(((seconds)%10)*22), 11,  16, false,(lastcolon*48/255));

//  if(lastcolon<160)
//draw_bitmap( 117, 24, small2Font+(((seconds)%10)*22), 11,  16, false,(((lastcolon/8)%16)+16)%16); //// top side

////draw_bitmap( 117, 24, small2Font+(((seconds +1 )%10)*22), 11,  16, false,(lastcolon*22/128)); //// bottom side funny

//// draw_bitmap( 117, 24, small2Font+(((seconds +1 )%10)*22), 11,  16, false,((256-lastcolon)*22/128)); //// bottom side funny


if(animating){
 draw_bitmap( 117, 32, small2Font+(((seconds  )%10)*22), 11,  16, false,(lastcolon*22/256)); //// top side

  draw_bitmap( 117, 32, small2Font+(((seconds +1 )%10)*22), 11,  16, false,((lastcolon-256)*22/256)); //// bottom side


}else{
  draw_bitmap( 117, 32, small2Font+(((seconds +1 )%10)*22), 11,  16, false,0); //// bottom side
speed=4;
}

///////////////////////////////////////////////////////////////////////////////////////
if(animating&&seconds%10==9||seconds==0 ){
 draw_bitmap( 104, 32, small2Font+(((seconds %60 )/10)*22), 11,  16, false,(lastcolon*22/256)); //// top side

  draw_bitmap( 104, 32, small2Font+((((seconds +1 )%60)/10)*22), 11,  16, false,((lastcolon-256)*22/256)); //// bottom side


}else{
  draw_bitmap( 104, 32, small2Font+((((seconds +1) %60 )/10)*22), 11,  16, false,0); //// bottom side

}
////////////////////////////////////////////////////////////////////////////////////////



//////////////////////////////
if(animating&&seconds==0){
//  draw_bitmap( 56, 16, font_mid+(((minutes+1)%10)*57), 19, 24, false, (lastcolon*24/256));
//  draw_bitmap( 56, 16, font_mid+(((minutes)%10)*57), 19, 24, false, ((lastcolon-256)*24/256));

  draw_bitmap( 78, 24, font_mid+(((minutes)%10)*57), 19, 24, false, (lastcolon*24/256));
  draw_bitmap( 78, 24, font_mid+(((minutes+1)%10)*57), 19, 24, false, ((lastcolon-256)*24/256));

}else{

//  draw_bitmap( 56, 16, font_mid+((minutes/10)*57), 19, 24, false, 0);
  draw_bitmap( 78, 24, font_mid+(((minutes+1)%10)*57), 19, 24, false, 0);

}

if(animating&&seconds==0&&minutes%10==9){
//  draw_bitmap( 56, 16, font_mid+(((minutes+1)%10)*57), 19, 24, false, (lastcolon*24/256));
//  draw_bitmap( 56, 16, font_mid+(((minutes)%10)*57), 19, 24, false, ((lastcolon-256)*24/256));

  draw_bitmap( 56, 24, font_mid+(((minutes)/10)*57), 19, 24, false, (lastcolon*24/256));
  draw_bitmap( 56, 24, font_mid+(((minutes+1)/10)*57), 19, 24, false, ((lastcolon-256)*24/256));

}else{

//  draw_bitmap( 56, 16, font_mid+((minutes/10)*57), 19, 24, false, 0);
  draw_bitmap( 56, 24, font_mid+(((minutes)/10)*57), 19, 24, false, 0);

}





      if(lastcolon<256){

    draw_bitmap(46,24,watchXui+144,6,24,false,0);




      }



if(lastcolon==160) speed=2;
if(lastcolon==210) speed=1;

if(lastcolon<256){
//curtm[0]++;

 lastcolon+=speed;
}
//else lastcolon=0;
}
 
