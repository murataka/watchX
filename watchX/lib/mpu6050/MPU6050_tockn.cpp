#include "MPU6050_tockn.h"
#include "Arduino.h"



	int16_t rawAccX, rawAccY, rawAccZ, rawTemp,
	rawGyroX, rawGyroY, rawGyroZ;

	float gyroXoffset, gyroYoffset, gyroZoffset;

	float temp, accX, accY, accZ, gyroX, gyroY, gyroZ;

	float angleGyroX, angleGyroY, angleGyroZ,
	angleAccX, angleAccY, angleAccZ;

	float angleX, angleY, angleZ;

	long interval, preInterval;

float accCoef =0.98, gyroCoef=0.02;



void MPU6050_begin(){
	uint8_t config[]={MPU6050_SMPLRT_DIV, 0x00,MPU6050_CONFIG, 0x00,MPU6050_GYRO_CONFIG, 0x08,MPU6050_ACCEL_CONFIG, 0x00,MPU6050_PWR_MGMT_1, 0x01};
 for(uint8_t a=0;a<sizeof(config);a++){

	 Wire.write(config[a]);
 }
	void MPU6050_update();
	angleGyroX = angleAccX;
	angleGyroY =angleAccY;
	angleGyroZ =angleAccZ;

}
/*
void  writeMPU6050(byte reg, byte data){
	Wire.beginTransmission(MPU6050_ADDR);
	Wire.write(reg);
	Wire.write(data);
	Wire.endTransmission();
}
*/
byte  readMPU6050(byte reg) {
	Wire.beginTransmission(MPU6050_ADDR);
	Wire.write(reg);
	Wire.endTransmission(true);
	Wire.requestFrom((uint8_t)MPU6050_ADDR, (size_t)2/*length*/);
	byte data =  Wire.read();
	Wire.read();
	return data;
}

void  setGyroOffsets(float x, float y, float z){
	gyroXoffset = x;
	gyroYoffset = y;
	gyroZoffset = z;
}

void  calcGyroOffsets( ){ //// DO NOT MOVE MPU6050 while calculating
	float x = 0, y = 0, z = 0;
	int16_t rx, ry, rz;


	for(int i = 0; i < 5000; i++){

		Wire.beginTransmission(MPU6050_ADDR);
		Wire.write(0x3B);
		Wire.endTransmission(false);
		Wire.requestFrom((int)MPU6050_ADDR, 14, (int)true);

		Wire.read() << 8 | Wire.read();
		Wire.read() << 8 | Wire.read();
		Wire.read() << 8 | Wire.read();
		Wire.read() << 8 | Wire.read();
		rx = Wire.read() << 8 | Wire.read();
		ry = Wire.read() << 8 | Wire.read();
		rz = Wire.read() << 8 | Wire.read();

		x += ((float)rx) / 65.5;
		y += ((float)ry) / 65.5;
		z += ((float)rz) / 65.5;
	}
	gyroXoffset = x / 5000;
	gyroYoffset = y / 5000;
	gyroZoffset = z / 5000;


}
void MPU6050_calc(){

		temp = (rawTemp + 12412.0) / 340.0;

		accX = ((float)rawAccX) / 16384.0;
		accY = ((float)rawAccY) / 16384.0;
		accZ = ((float)rawAccZ) / 16384.0;

		angleAccX = atan2(accY, accZ + abs(accX)) * 360 / 2.0 / PI;
		angleAccY = atan2(accX, accZ + abs(accY)) * 360 / -2.0 / PI;

		gyroX = ((float)rawGyroX) / 65.5;
		gyroY = ((float)rawGyroY) / 65.5;
		gyroZ = ((float)rawGyroZ) / 65.5;

		interval = millis() - preInterval;

		gyroX -= gyroXoffset;
		gyroY -= gyroYoffset;
		gyroZ -= gyroZoffset;

		angleGyroX += gyroX * (interval * 0.001);
		angleGyroY += gyroY * (interval * 0.001);
		angleGyroZ += gyroZ * (interval * 0.001);

		preInterval = millis();

		angleX = (gyroCoef * angleGyroX) + (accCoef * angleAccX);
		angleY = (gyroCoef * angleGyroY) + (accCoef * angleAccY);
		angleZ = angleGyroZ;

}
void MPU6050_update(){
	Wire.beginTransmission(MPU6050_ADDR);
	Wire.write(0x3B);
	Wire.endTransmission(false);
	Wire.requestFrom((int)MPU6050_ADDR, 14, (int)true);

	rawAccX = Wire.read() << 8 | Wire.read();
	rawAccY = Wire.read() << 8 | Wire.read();
	rawAccZ = Wire.read() << 8 | Wire.read();
	rawTemp = Wire.read() << 8 | Wire.read();
	rawGyroX = Wire.read() << 8 | Wire.read();
	rawGyroY = Wire.read() << 8 | Wire.read();
	rawGyroZ = Wire.read() << 8 | Wire.read();

}
