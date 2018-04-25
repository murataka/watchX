#ifndef RTC_H
#define RTC_H
#define DS3231_I2C_ADDRESS 0x68
extern volatile unsigned char curtm[];
#define seconds curtm[0]
#define minutes curtm[1]
#define hours curtm[2]
#define day curtm[3]
#define date curtm[4]
#define month curtm[5]
#define year curtm[6]

//seconds, minutes, hours, day, date, month, year;



void getDateTime();
void setDateTime();
void startSqw();
void stopSqw();
void setDateTime();
#endif
