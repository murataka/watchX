#ifndef RTC_H
#define RTC_H
#define DS3231_I2C_ADDRESS 0x68
extern unsigned char curtm[];
#define seconds curtm[0] %60
#define minutes curtm[1]%60
#define hours curtm[2]%24
#define day curtm[3]
#define date curtm[4]
#define month curtm[5]
#define year curtm[6]

//seconds, minutes, hours, day, date, month, year;

#define decToBcd(val) ( (val/10*16) + (val%10) )
void get3231Date();
void set3231Date();
#endif
