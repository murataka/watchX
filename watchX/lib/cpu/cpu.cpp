
#include "cpu.h"
#include <Arduino.h>
void setPrescale() {

  /*
   * Setting the Prescale is a timed event,
   * meaning that two MCU instructions must be executed
   * within a few clockcycles.
   */

  //To ensure timed events, first turn off interrupts
  cli();                   // Disable interrupts
  CLKPR = _BV(CLKPCE);     //  Enable change. Write the CLKPCE bit to one and all the other to zero. Within 4 clock cycles, set CLKPR again
  CLKPR = CLOCK_PRESCALE_DEFAULT; // Change clock division. Write the CLKPS0..3 bits while writing the CLKPE bit to zero
  sei();                   // Enable interrupts


  // To get the fastest (and still reliable) ADC (Analog to Digital Converter)
  // operations, when changing the prescale register,
  // you also need to set the ADC_Clk_prescale in the ADCSRA register

                                                     // Preferred: 50KHz < ADC_Clk < 200KHz
#if  CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_1
#define ADC_SPEED 7                                  //ADC_Clk = F_CPU_Pre / 128 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_2
#define ADC_SPEED 6                                  //ADC_Clk = F_CPU_Pre /  64 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_4
#define ADC_SPEED 5                                  //ADC_Clk = F_CPU_Pre /  32 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_8
#define ADC_SPEED 4                                  //ADC_Clk = F_CPU_Pre /  16 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_16
#define ADC_SPEED 3                                  //ADC_Clk = F_CPU_Pre /   8 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_32
#define ADC_SPEED 2                                  //ADC_Clk = F_CPU_Pre /   4 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_64
#define ADC_SPEED 1                                  //ADC_Clk = F_CPU_Pre /   2 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_128
#define ADC_SPEED 0                                  //ADC_Clk = F_CPU_Pre /   1 => 125KHz
#elif CLOCK_PRESCALE_DEFAULT == CLOCK_PRESCALER_256
#define ADC_SPEED 0                                  //ADC_Clk = F_CPU_Pre /   1 => 62.5KHz
#endif

  ADCSRA = ( 0x80 | ADC_SPEED);  // Activate ADC and set ADC_Clk
}
