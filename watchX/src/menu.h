#ifndef MENU_H
#define MENU_H
//#include <ssd1306.h>
#include "resources.h"

//#define MENU_LENGTH 8
extern uint8_t menuapp;
  extern int menuindex;
  extern int menuspeed;
  #define MENUCOUNT 0x06
#define MENU_WATCH 0
#define MENU_SETTINGS_EXIT 0
#define MENU_STOPWATCH 1
#define MENU_GYROCUBE 2
<<<<<<< HEAD
#define MENU_SETTINGS_BLUETOOTH 2
=======
>>>>>>> 5931df99f01437ea40f2eae201c02fee232dc899
#define MENU_TORCH 3

#define MENU_BLUETOOTH 4
#define MENU_SETTINGS 5

void drawMenus( );

void menusw1( );
void menusw2( );
void menusw3( );

#endif
