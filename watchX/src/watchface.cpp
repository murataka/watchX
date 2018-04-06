#include "watchX.h"
#include "watchface.h"
#include "rtc.h"
#include "oled.h"
#include "cpu.h"
//#include <nano_gfx.h>


 uint8_t watchMode=0;

//uint8_t buf2[16*2];


  int speed;


//unsigned int i=0;


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
void drawWatchFace( ){

if(watchMode==0){
  unsigned char b[16] ="    00     2000";
memcpy(b,days[day],3);

memcpy(b+7,months[month],3);

  b[13]+=year/10;
  b[14]+=year%10;
  b[4]+=date/10;
  b[5]+=date%10;

drawString(20,0,b,smallFont);


}


  draw_bitmap( 0, 24, font_mid+((hours/10)*57), 19, 24, false, 0);
  draw_bitmap( 22, 24, font_mid+((hours%10)*57), 19, 24, false, 0);



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
