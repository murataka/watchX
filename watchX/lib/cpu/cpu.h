#ifndef CPU_H
#define CPU_H

#define CLOCK_PRESCALER_1   (0x0)  //  16MHz   (FYI: 15mA   on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_2   (0x1)  //   8MHz   (FYI: 10mA   on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_4   (0x2)  //   4MHz   (FYI:  8mA   on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_8   (0x3)  //   2MHz   (FYI:  6.5mA on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_16  (0x4)  //   1MHz   (FYI:  5.5mA on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_32  (0x5)  // 500KHz   (FYI:  5mA   on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_64  (0x6)  // 250KHz   (FYI:  4.8mA on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_128 (0x7)  // 125KHz   (FYI:  4.8mA on an Arduino Pro Mini @5V Vcc w. LEDs removed)
#define CLOCK_PRESCALER_256 (0x8)  // 62.5KHz  (FYI:  4.6mA on an Arduino Pro Mini @5V Vcc w. LEDs removed)

void setPrescale();

#define    CLOCK_PRESCALE_DEFAULT   CLOCK_PRESCALER_1

//#define CLOCK_DIVIDER pow(CLOCK_PRESCALE_DEFAULT,2)
#endif
