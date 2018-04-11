#include "gyrocube.h"
#include "oled.h"
#include <tinyMpu6050.h>

#include "watchX.h"
//3D_Cube for Arduino OLED module by Colin Ord, 9/1/2015
//A port of my original JustBasic Cube_3D demo to the Arduino Uno using U8G library.



float r, x1, ya, z1, x2, y2, z2, x3, y3, z3;               //
int f[8][2];                                               // Draw box
//int x = 64;                                                // 64=128/2
//int y = 32;
int16_t a;                                             // 32= 64/2

void gyroCube(uint8_t scale){
float sinr,cosr;


int8_t c[8][3] = {                                            // Cube
 {-20,-20, 20},{20,-20, 20},{20,20, 20},{-20,20, 20},      //
 {-20,-20,-20},{20,-20,-20},{20,20,-20},{-20,20,-20} };    //


if(functions[uiFunc]!=drawGyroCube)
a++;
else
if(animation_offsetY==0)
 a=ac[4]/50;

  for(uint8_t i=0;i<8;i++){
c[i][0]=c[i][0]>0?scale:-scale;
    c[i][1]=c[i][1]>0?scale:-scale;
    c[i][2]=c[i][2]>0?scale:-scale;
  }

  //for (int a = 0; a <= 360; a = a + 3 ) {                   // 0 to 360 deg 3step
    for (int i = 0; i < 8; i++) {                           //
     r  = a * 0.0174532;
          cosr=cos(r); sinr=sin(r);                               // 1 degree
     x1 = c[i][2] * sinr + c[i][0] * cosr;              // rotate Y
     ya = c[i][1];                                          //
     z1 = c[i][2] * cosr - c[i][0] * sinr;              //
     x2 = x1;                                               //
     y2 = ya * cosr - z1 * sinr;                        // rotate X
     z2 = ya * sinr + z1 * cosr;                        //
     x3 = x2 * cosr - y2 * sinr;                        // rotate Z
     y3 = x2 * sinr + y2 * cosr;                        //
     z3 = z2;                                               //
     x3 = x3 + 64 ;                                          //
     y3 = y3 + 32 ;                                          //
     f[i][0] = x3;                                          // store new values
     f[i][1] = y3;                                          //
     f[i][2] = z3;                                          //
    }                                                       //

    drawLine(f[0][0],f[0][1],f[1][0],f[1][1]);//
    drawLine(f[1][0],f[1][1],f[2][0],f[2][1]);//
    drawLine(f[2][0],f[2][1],f[3][0],f[3][1]);//
    drawLine(f[3][0],f[3][1],f[0][0],f[0][1]);//
    drawLine(f[4][0],f[4][1],f[5][0],f[5][1]);//
    drawLine(f[5][0],f[5][1],f[6][0],f[6][1]);//
    drawLine(f[6][0],f[6][1],f[7][0],f[7][1]);//
    drawLine(f[7][0],f[7][1],f[4][0],f[4][1]);//
    drawLine(f[0][0],f[0][1],f[4][0],f[4][1]);//
    drawLine(f[1][0],f[1][1],f[5][0],f[5][1]);//
    drawLine(f[2][0],f[2][1],f[6][0],f[6][1]);//
    drawLine(f[3][0],f[3][1],f[7][0],f[7][1]);//

    drawLine(f[1][0],f[1][1],f[3][0],f[3][1]);// cross
    drawLine(f[0][0],f[0][1],f[2][0],f[2][1]);// cross
                      //  delay(1000);                     //
//  }


}
void drawGyroCube(){

gyroCube(16);

}
