#ifndef MENU_H
#define MENU_H
//#include <ssd1306.h>
#include "resources.h"

//#define MENU_LENGTH 8
  extern int menuindex;
  extern int menuspeed;
#define MENU_WATCH 0
#define MENU_STOPWATCH 1
#define MENU_GYROCUBE 2
#define MENU_DIAGNOSTIC 3
#define MENU_BLUETOOTH 4
#define MENU_SETTINGS 5

void drawMenus( );

void menusw1( );
void menusw2( );
void menusw3( );

#endif
