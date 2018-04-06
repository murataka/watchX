#ifndef MPU6050_H
#define MPU6050_H
#include <Arduino.h>
 
extern int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;
void updateMpu6050();
void startMpu6050();
#endif
