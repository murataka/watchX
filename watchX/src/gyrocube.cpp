#include "gyrocube.h"
#include "watchX.h"
#include "oled.h"
#include "gyroaccel.h"



// Overall scale and perspective distance
uint8_t sZ = 4, scale = 8;
// screen center
uint8_t centerX = 64;
uint8_t centerY = 32;

// Initialize cube point arrays
double C1[] = {  1,  1,  1 };
double C2[] = {  1,  1, -1 };
double C3[] = {  1, -1,  1 };
double C4[] = {  1, -1, -1 };
double C5[] = { -1,  1,  1 };
double C6[] = { -1,  1, -1 };
double C7[] = { -1, -1,  1 };
double C8[] = { -1, -1, -1 };

// Initialize cube points coords
uint8_t P1[] = { 0, 0 };
uint8_t P2[] = { 0, 0 };
uint8_t P3[] = { 0, 0 };
uint8_t P4[] = { 0, 0 };
uint8_t P5[] = { 0, 0 };
uint8_t P6[] = { 0, 0 };
uint8_t P7[] = { 0, 0 };
uint8_t P8[] = { 0, 0 };

void vectRotXYZ(double angle, int axe) {
  int8_t m1; // coords polarity
  uint8_t i1, i2; // coords index

  switch(axe) {
    case 1: // X
      i1 = 1; // y
      i2 = 2; // z
      m1 = -1;
    break;
    case 2: // Y
      i1 = 0; // x
      i2 = 2; // z
      m1 = 1;
    break;
    case 3: // Z
      i1 = 0; // x
      i2 = 1; // y
      m1 = 1;
    break;
  }

  double t1 = C1[i1];
  double t2 = C1[i2];
  C1[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C1[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C2[i1];
  t2 = C2[i2];
  C2[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C2[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C3[i1];
  t2 = C3[i2];
  C3[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C3[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C4[i1];
  t2 = C4[i2];
  C4[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C4[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C5[i1];
  t2 = C5[i2];
  C5[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C5[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C6[i1];
  t2 = C6[i2];
  C6[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C6[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C7[i1];
  t2 = C7[i2];
  C7[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C7[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

  t1 = C8[i1];
  t2 = C8[i2];
  C8[i1] = t1*cos(angle)+(m1*t2)*sin(angle);
  C8[i2] = (-m1*t1)*sin(angle)+t2*cos(angle);

}

void gyroCube(uint8_t scale){
  // scale angles down, rotate
  //char r=(rand()%20)==0?r:(rand()%3)-1;
char r=1;
  vectRotXYZ((double)0.03*r, (millis()/1000)%3+1); // X
  //vectRotXYZ((double)-gx/MMPI_TIME, 2); // Y
  //vectRotXYZ((double)gz/MMPI_TIME, 3); // Z

  // calculate each point coords
  P1[0] = centerX + scale/(1+C1[2]/sZ)*C1[0]; P1[1] = centerY + scale/(1+C1[2]/sZ)*C1[1];
  P2[0] = centerX + scale/(1+C2[2]/sZ)*C2[0]; P2[1] = centerY + scale/(1+C2[2]/sZ)*C2[1];
  P3[0] = centerX + scale/(1+C3[2]/sZ)*C3[0]; P3[1] = centerY + scale/(1+C3[2]/sZ)*C3[1];
  P4[0] = centerX + scale/(1+C4[2]/sZ)*C4[0]; P4[1] = centerY + scale/(1+C4[2]/sZ)*C4[1];
  P5[0] = centerX + scale/(1+C5[2]/sZ)*C5[0]; P5[1] = centerY + scale/(1+C5[2]/sZ)*C5[1];
  P6[0] = centerX + scale/(1+C6[2]/sZ)*C6[0]; P6[1] = centerY + scale/(1+C6[2]/sZ)*C6[1];
  P7[0] = centerX + scale/(1+C7[2]/sZ)*C7[0]; P7[1] = centerY + scale/(1+C7[2]/sZ)*C7[1];
  P8[0] = centerX + scale/(1+C8[2]/sZ)*C8[0]; P8[1] = centerY + scale/(1+C8[2]/sZ)*C8[1];

  // draw each cube edge
  drawLine(P1[0], P1[1], P2[0], P2[1]); //1-2
  drawLine(P1[0], P1[1], P3[0], P3[1]); //1-3
  drawLine(P1[0], P1[1], P5[0], P5[1]); //1-5
  drawLine(P2[0], P2[1], P4[0], P4[1]); //2-4
  drawLine(P2[0], P2[1], P6[0], P6[1]); //2-6
  drawLine(P3[0], P3[1], P4[0], P4[1]); //3-4
  drawLine(P3[0], P3[1], P7[0], P7[1]); //3-7
  drawLine(P4[0], P4[1], P8[0], P8[1]); //4-8
  drawLine(P5[0], P5[1], P6[0], P6[1]); //5-6
  drawLine(P5[0], P5[1], P7[0], P7[1]); //5-7
  drawLine(P6[0], P6[1], P8[0], P8[1]); //6-8
  drawLine(P7[0], P7[1], P8[0], P8[1]); //7-8




}
void drawGyroCube(){

gyroCube(16);
}
