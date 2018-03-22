#include "timerone.h"

func_type timerOneFunc=NULL;
void startTimerOne(){

  cli();//stop interrupts
  TCCR1A = 0;// set entire TCCR1A register to 0
  TCCR1B = 0;// same for TCCR1B
  TCNT1  = 0;//initialize counter value to 0
  OCR1A = 781; // approximately 20Hz
  TCCR1B |= (1 << WGM12);// turn on CTC mode
  TCCR1B |= (1 << CS12) | (1 << CS10);  // 1024 presxaler
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  sei();//allow interrupts

}

ISR(TIMER1_COMPA_vect){
if(timerOneFunc)timerOneFunc(); /// TODO : multiple timerone handler functions

}
