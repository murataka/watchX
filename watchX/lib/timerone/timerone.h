#ifndef TIMERONE_H
#define TIMERONE_H
#include <Arduino.h>


#ifndef func_type
typedef void (*func_type)(  bool fromfunction   );
#endif

extern func_type timerOneFunc;

void startTimerOne();
#endif
