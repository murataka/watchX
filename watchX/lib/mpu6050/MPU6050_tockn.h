#ifndef MPU6050_TOCKN_H
#define MPU6050_TOCKN_H

#include <Arduino.h>
#include <Wire.h>


#define MPU6050_ADDR         0x69
#define MPU6050_SMPLRT_DIV   0x19
#define MPU6050_CONFIG       0x1a
#define MPU6050_GYRO_CONFIG  0x1b
#define MPU6050_ACCEL_CONFIG 0x1c
#define MPU6050_WHO_AM_I     0x75
#define MPU6050_PWR_MGMT_1   0x6b
#define MPU6050_TEMP_H       0x41
#define MPU6050_TEMP_L       0x42



extern int16_t rawAccX, rawAccY, rawAccZ, rawTemp,
rawGyroX, rawGyroY, rawGyroZ;

extern float gyroXoffset, gyroYoffset, gyroZoffset;

extern float temp, accX, accY, accZ, gyroX, gyroY, gyroZ;

extern float angleGyroX, angleGyroY, angleGyroZ,
angleAccX, angleAccY, angleAccZ;

extern float angleX, angleY, angleZ;

extern long interval, preInterval;

extern float accCoef , gyroCoef;


//void writeMPU6050(byte reg, byte data);
byte readMPU6050(byte reg);
void setGyroOffsets(float x, float y, float z);
void calcGyroOffsets( );
void MPU6050_update();
void MPU6050_calc();


 void MPU6050_begin();



#endif
