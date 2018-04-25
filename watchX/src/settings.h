#ifndef SETTINGS_H
#define SETTINGS_H


 

//extern struct Settings EEMEM st;

#define BLOOTOOTH_STATE devices&0B1

extern uint8_t devices;

void drawSettings();

void settingsSw1();

void settingsSw2();

#endif
