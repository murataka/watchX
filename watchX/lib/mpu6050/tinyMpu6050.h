#ifndef MPU6050_H
#define MPU6050_H
#include <Arduino.h>

extern int16_t ac[7];
void updateMpu6050();
void startMpu6050();
#endif
