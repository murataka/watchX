#ifndef MENU_H
#define MENU_H
//#include <ssd1306.h>
#include "resources.h"

//#define MENU_LENGTH 8
  extern int menuindex;
  extern int speed;
#define MENU_WATCH 0
#define MENU_STOPWATCH 1
#define MENU_GYROCUBE 2
void drawMenus( );

void menusw1( );
void menusw2( );
void menusw3( );

#endif
