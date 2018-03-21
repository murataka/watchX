/**
 * @file ArduboyTones.h
 * \brief An Arduino library for playing tones and tone sequences,
 * intended for the Arduboy game system.
 */

/*****************************************************************************
  ArduboyTones

An Arduino library to play tones and tone sequences.

Specifically written for use by the Arduboy miniature game system
https://www.arduboy.com/
but could work with other Arduino AVR boards that have 16 bit timer 3
available, by changing the port and bit definintions for the pin(s)
if necessary.

Copyright (c) 2017 Scott Allen

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*****************************************************************************/

#ifndef TONES_H
#define TONES_H

#include <Arduino.h>

// ************************************************************
// ***** Values to use as function parameters in sketches *****
// ************************************************************

/** \brief
 * Frequency value for sequence termination. (No duration follows)
 */
#define TONES_END 0x8000

/** \brief
 * Frequency value for sequence repeat. (No duration follows)
 */
#define TONES_REPEAT 0x8001


/** \brief
 * Add this to the frequency to play a tone at high volume
 */
#define TONE_HIGH_VOLUME 0x8000


/** \brief
 * `volumeMode()` parameter. Use the volume encoded in each tone's frequency
 */
#define VOLUME_IN_TONE 0

/** \brief
 * `volumeMode()` parameter. Play all tones at normal volume, ignoring
 * what's encoded in the frequencies
 */
#define VOLUME_ALWAYS_NORMAL 1

/** \brief
 * `volumeMode()` parameter. Play all tones at high volume, ignoring
 * what's encoded in the frequencies
 */
#define VOLUME_ALWAYS_HIGH 2

// ************************************************************


#ifndef AB_DEVKIT
  // ***** SPEAKER ON TWO PINS *****
  // Indicates that each of the speaker leads is attached to a pin, the way
  // the Arduboy is wired. Allows tones of a higher volume to be produced.
  // If commented out only one speaker pin will be used. The other speaker
  // lead should be attached to ground.
  #define TONES_2_SPEAKER_PINS
  // *******************************

  // ***** VOLUME HIGH/NORMAL SUPPORT *****
  // With the speaker placed across two pins, higher volume is produced by
  // toggling the second pin to the opposite state of the first pin.
  // Normal volume is produced by leaving the second pin low.
  // Comment this out for only normal volume support, which will slightly
  // reduce the code size.
  #define TONES_VOLUME_CONTROL
  // **************************************

  #ifdef TONES_VOLUME_CONTROL
    // Must be defined for volume control, so force it if necessary.
    #define TONES_2_SPEAKER_PINS
  #endif
#endif

// ***** CONTROL THE TIMER CLOCK PRESCALER ****
// Uncommenting this will switch the timer clock to use no prescaler,
// instead of a divide by 8 prescaler, if the frequency is high enough to
// allow it. This will result in higher frequencies being more accurate at
// the expense of requiring more code. If left commented out, a divide by 8
// prescaler will be used for all frequencies.
//#define TONES_ADJUST_PRESCALER
// ********************************************

// This must match the maximum number of tones that can be specified in
// the tone() function.
#define MAX_TONES 3

#ifndef AB_DEVKIT
  // Arduboy speaker pin 1 = Arduino pin 5 = ATmega32u4 PC6
  #define TONE_PIN_PORT PORTB
  #define TONE_PIN_DDR DDRB
  #define TONE_PIN PORTB5
  #define TONE_PIN_MASK _BV(TONE_PIN)
  // Arduboy speaker pin 2 = Arduino pin 13 = ATmega32u4 PC7
  #define TONE_PIN2_PORT PORTB
  #define TONE_PIN2_DDR DDRB
  #define TONE_PIN2 PORTB5
  #define TONE_PIN2_MASK _BV(TONE_PIN2)
#else
  // DevKit speaker pin 1 = Arduino pin A2 = ATmega32u4 PF5
  #define TONE_PIN_PORT PORTB
  #define TONE_PIN_DDR DDRB
  #define TONE_PIN PORTB5
  #define TONE_PIN_MASK _BV(TONE_PIN)
#endif

// The minimum frequency that can be produced without a clock prescaler.
#define MIN_NO_PRESCALE_FREQ ((uint16_t)(((F_CPU / 2L) + (1L << 16) - 1L) / (1L << 16)))

// Dummy frequency used to for silent tones (rests).
#define SILENT_FREQ 250


/** \brief
 * The ArduboyTones class for generating tones by specifying
 * frequency/duration pairs.
 */
class Tones
{
 public:
  /** \brief
   * The ArduboyTones class constructor.
   *
   * \param outEn A function which returns a boolean value of `true` if sound
   * should be played or `false` if sound should be muted. This function will
   * be called from the timer interrupt service routine, at the start of each
   * tone, so it should be as fast as possible.
   */
  Tones(bool (*outEn)());

  /** \brief
   * Play a single tone.
   *
   * \param freq The frequency of the tone, in hertz.
   * \param dur The duration to play the tone for, in 1024ths of a
   * second (very close to milliseconds). A duration of 0, or if not provided,
   * means play forever, or until `noTone()` is called or a new tone or
   * sequence is started.
   */
  static void tone(uint16_t freq, uint16_t dur = 0);

  /** \brief
   * Play two tones in sequence.
   *
   * \param freq1,freq2 The frequency of the tone in hertz.
   * \param dur1,dur2 The duration to play the tone for, in 1024ths of a
   * second (very close to milliseconds).
   */
  static void tone(uint16_t freq1, uint16_t dur1,
                   uint16_t freq2, uint16_t dur2);

  /** \brief
   * Play three tones in sequence.
   *
   * \param freq1,freq2,freq3 The frequency of the tone, in hertz.
   * \param dur1,dur2,dur3 The duration to play the tone for, in 1024ths of a
   * second (very close to milliseconds).
   */
  static void tone(uint16_t freq1, uint16_t dur1,
                   uint16_t freq2, uint16_t dur2,
                   uint16_t freq3, uint16_t dur3);

  /** \brief
   * Play a tone sequence from frequency/duration pairs in a PROGMEM array.
   *
   * \param tones A pointer to an array of frequency/duration pairs.
   * The array must be placed in code space using `PROGMEM`.
   *
   * \details
   * \parblock
   * See the `tone()` function for details on the frequency and duration values.
   * A frequency of 0 for any tone means silence (a musical rest).
   *
   * The last element of the array must be `TONES_END` or `TONES_REPEAT`.
   *
   * Example:
   *
   * \code
   * const uint16_t sound1[] PROGMEM = {
   *   220,1000, 0,250, 440,500, 880,2000,
   *   TONES_END
   * };
   * \endcode
   *
   * \endparblock
   */
  static void tones(const uint16_t *tones);

  /** \brief
   * Play a tone sequence from frequency/duration pairs in an array in RAM.
   *
   * \param tones A pointer to an array of frequency/duration pairs.
   * The array must be located in RAM.
   *
   * \see tones()
   *
   * \details
   * \parblock
   * See the `tone()` function for details on the frequency and duration values.
   * A frequency of 0 for any tone means silence (a musical rest).
   *
   * The last element of the array must be `TONES_END` or `TONES_REPEAT`.
   *
   * Example:
   *
   * \code
   * uint16_t sound2[] = {
   *   220,1000, 0,250, 440,500, 880,2000,
   *   TONES_END
   * };
   * \endcode
   *
   * \endparblock
   *
   * \note Using `tones()`, with the data in PROGMEM, is normally a better
   * choice. The only reason to use tonesInRAM() would be if dynamically
   * altering the contents of the array is required.
   */
  static void tonesInRAM(uint16_t *tones);

  /** \brief
   * Stop playing the tone or sequence.
   *
   * \details
   * If a tone or sequence is playing, it will stop. If nothing
   * is playing, this function will do nothing.
   */
  static void noTone();

  /** \brief
   * Set the volume to always normal, always high, or tone controlled.
   *
   * \param mode
   * \parblock
   * One of the following values should be used:
   *
   * - `VOLUME_IN_TONE` The volume of each tone will be specified in the tone
   *    itself.
   * - `VOLUME_ALWAYS_NORMAL` All tones will play at the normal volume level.
   * - `VOLUME_ALWAYS_HIGH` All tones will play at the high volume level.
   *
   * \endparblock
   */
  static void volumeMode(uint8_t mode);

  /** \brief
   * Check if a tone or tone sequence is playing.
   *
   * \return boolean `true` if playing (even if sound is muted).
   */
  static bool playing();

private:
  // Get the next value in the sequence
  static uint16_t getNext();

public:
  // Called from ISR so must be public. Should not be called by a program.
  static void nextTone();
};


#define NOTE_REST 0
#define NOTE_C0  16
#define NOTE_CS0 17
#define NOTE_D0  18
#define NOTE_DS0 19
#define NOTE_E0  21
#define NOTE_F0  22
#define NOTE_FS0 23
#define NOTE_G0  25
#define NOTE_GS0 26
#define NOTE_A0  28
#define NOTE_AS0 29
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2218
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define NOTE_E8  5274
#define NOTE_F8  5588
#define NOTE_FS8 5920
#define NOTE_G8  6272
#define NOTE_GS8 6645
#define NOTE_A8  7040
#define NOTE_AS8 7459
#define NOTE_B8  7902
#define NOTE_C9  8372
#define NOTE_CS9 8870
#define NOTE_D9  9397
#define NOTE_DS9 9956
#define NOTE_E9  10548
#define NOTE_F9  11175
#define NOTE_FS9 11840
#define NOTE_G9  12544
#define NOTE_GS9 13290
#define NOTE_A9  14080
#define NOTE_AS9 14917
#define NOTE_B9  15804

#define NOTE_C0H  (NOTE_C0 + TONE_HIGH_VOLUME)
#define NOTE_CS0H (NOTE_CS0 + TONE_HIGH_VOLUME)
#define NOTE_D0H  (NOTE_D08 + TONE_HIGH_VOLUME)
#define NOTE_DS0H (NOTE_DS0 + TONE_HIGH_VOLUME)
#define NOTE_E0H  (NOTE_E0 + TONE_HIGH_VOLUME)
#define NOTE_F0H  (NOTE_F0 + TONE_HIGH_VOLUME)
#define NOTE_FS0H (NOTE_FS0 + TONE_HIGH_VOLUME)
#define NOTE_G0H  (NOTE_G0 + TONE_HIGH_VOLUME)
#define NOTE_GS0H (NOTE_GS0 + TONE_HIGH_VOLUME)
#define NOTE_A0H  (NOTE_A0 + TONE_HIGH_VOLUME)
#define NOTE_AS0H (NOTE_AS0 + TONE_HIGH_VOLUME)
#define NOTE_B0H  (NOTE_B0 + TONE_HIGH_VOLUME)
#define NOTE_C1H  (NOTE_C1 + TONE_HIGH_VOLUME)
#define NOTE_CS1H (NOTE_CS1 + TONE_HIGH_VOLUME)
#define NOTE_D1H  (NOTE_D1 + TONE_HIGH_VOLUME)
#define NOTE_DS1H (NOTE_DS1 + TONE_HIGH_VOLUME)
#define NOTE_E1H  (NOTE_E1 + TONE_HIGH_VOLUME)
#define NOTE_F1H  (NOTE_F1 + TONE_HIGH_VOLUME)
#define NOTE_FS1H (NOTE_FS1 + TONE_HIGH_VOLUME)
#define NOTE_G1H  (NOTE_G1 + TONE_HIGH_VOLUME)
#define NOTE_GS1H (NOTE_GS1 + TONE_HIGH_VOLUME)
#define NOTE_A1H  (NOTE_A1 + TONE_HIGH_VOLUME)
#define NOTE_AS1H (NOTE_AS1 + TONE_HIGH_VOLUME)
#define NOTE_B1H  (NOTE_B1 + TONE_HIGH_VOLUME)
#define NOTE_C2H  (NOTE_C2 + TONE_HIGH_VOLUME)
#define NOTE_CS2H (NOTE_CS2 + TONE_HIGH_VOLUME)
#define NOTE_D2H  (NOTE_D2 + TONE_HIGH_VOLUME)
#define NOTE_DS2H (NOTE_DS2 + TONE_HIGH_VOLUME)
#define NOTE_E2H  (NOTE_E2 + TONE_HIGH_VOLUME)
#define NOTE_F2H  (NOTE_F2 + TONE_HIGH_VOLUME)
#define NOTE_FS2H (NOTE_FS2 + TONE_HIGH_VOLUME)
#define NOTE_G2H  (NOTE_G2 + TONE_HIGH_VOLUME)
#define NOTE_GS2H (NOTE_GS2 + TONE_HIGH_VOLUME)
#define NOTE_A2H  (NOTE_A2 + TONE_HIGH_VOLUME)
#define NOTE_AS2H (NOTE_AS2 + TONE_HIGH_VOLUME)
#define NOTE_B2H  (NOTE_B2 + TONE_HIGH_VOLUME)
#define NOTE_C3H  (NOTE_C3 + TONE_HIGH_VOLUME)
#define NOTE_CS3H (NOTE_CS3 + TONE_HIGH_VOLUME)
#define NOTE_D3H  (NOTE_D3 + TONE_HIGH_VOLUME)
#define NOTE_DS3H (NOTE_DS3 + TONE_HIGH_VOLUME)
#define NOTE_E3H  (NOTE_E3 + TONE_HIGH_VOLUME)
#define NOTE_F3H  (NOTE_F3 + TONE_HIGH_VOLUME)
#define NOTE_FS3H (NOTE_F3 + TONE_HIGH_VOLUME)
#define NOTE_G3H  (NOTE_G3 + TONE_HIGH_VOLUME)
#define NOTE_GS3H (NOTE_GS3 + TONE_HIGH_VOLUME)
#define NOTE_A3H  (NOTE_A3 + TONE_HIGH_VOLUME)
#define NOTE_AS3H (NOTE_AS3 + TONE_HIGH_VOLUME)
#define NOTE_B3H  (NOTE_B3 + TONE_HIGH_VOLUME)
#define NOTE_C4H  (NOTE_C4 + TONE_HIGH_VOLUME)
#define NOTE_CS4H (NOTE_CS4 + TONE_HIGH_VOLUME)
#define NOTE_D4H  (NOTE_D4 + TONE_HIGH_VOLUME)
#define NOTE_DS4H (NOTE_DS4 + TONE_HIGH_VOLUME)
#define NOTE_E4H  (NOTE_E4 + TONE_HIGH_VOLUME)
#define NOTE_F4H  (NOTE_F4 + TONE_HIGH_VOLUME)
#define NOTE_FS4H (NOTE_FS4 + TONE_HIGH_VOLUME)
#define NOTE_G4H  (NOTE_G4 + TONE_HIGH_VOLUME)
#define NOTE_GS4H (NOTE_GS4 + TONE_HIGH_VOLUME)
#define NOTE_A4H  (NOTE_A4 + TONE_HIGH_VOLUME)
#define NOTE_AS4H (NOTE_AS4 + TONE_HIGH_VOLUME)
#define NOTE_B4H  (NOTE_B4 + TONE_HIGH_VOLUME)
#define NOTE_C5H  (NOTE_C5 + TONE_HIGH_VOLUME)
#define NOTE_CS5H (NOTE_CS5 + TONE_HIGH_VOLUME)
#define NOTE_D5H  (NOTE_D5 + TONE_HIGH_VOLUME)
#define NOTE_DS5H (NOTE_DS5 + TONE_HIGH_VOLUME)
#define NOTE_E5H  (NOTE_E5 + TONE_HIGH_VOLUME)
#define NOTE_F5H  (NOTE_F5 + TONE_HIGH_VOLUME)
#define NOTE_FS5H (NOTE_FS5 + TONE_HIGH_VOLUME)
#define NOTE_G5H  (NOTE_G5 + TONE_HIGH_VOLUME)
#define NOTE_GS5H (NOTE_GS5 + TONE_HIGH_VOLUME)
#define NOTE_A5H  (NOTE_A5 + TONE_HIGH_VOLUME)
#define NOTE_AS5H (NOTE_AS5 + TONE_HIGH_VOLUME)
#define NOTE_B5H  (NOTE_B5 + TONE_HIGH_VOLUME)
#define NOTE_C6H  (NOTE_C6 + TONE_HIGH_VOLUME)
#define NOTE_CS6H (NOTE_CS6 + TONE_HIGH_VOLUME)
#define NOTE_D6H  (NOTE_D6 + TONE_HIGH_VOLUME)
#define NOTE_DS6H (NOTE_DS6 + TONE_HIGH_VOLUME)
#define NOTE_E6H  (NOTE_E6 + TONE_HIGH_VOLUME)
#define NOTE_F6H  (NOTE_F6 + TONE_HIGH_VOLUME)
#define NOTE_FS6H (NOTE_FS6 + TONE_HIGH_VOLUME)
#define NOTE_G6H  (NOTE_G6 + TONE_HIGH_VOLUME)
#define NOTE_GS6H (NOTE_GS6 + TONE_HIGH_VOLUME)
#define NOTE_A6H  (NOTE_A6 + TONE_HIGH_VOLUME)
#define NOTE_AS6H (NOTE_AS6 + TONE_HIGH_VOLUME)
#define NOTE_B6H  (NOTE_B6 + TONE_HIGH_VOLUME)
#define NOTE_C7H  (NOTE_C7 + TONE_HIGH_VOLUME)
#define NOTE_CS7H (NOTE_CS7 + TONE_HIGH_VOLUME)
#define NOTE_D7H  (NOTE_D7 + TONE_HIGH_VOLUME)
#define NOTE_DS7H (NOTE_DS7 + TONE_HIGH_VOLUME)
#define NOTE_E7H  (NOTE_E7 + TONE_HIGH_VOLUME)
#define NOTE_F7H  (NOTE_F7 + TONE_HIGH_VOLUME)
#define NOTE_FS7H (NOTE_FS7 + TONE_HIGH_VOLUME)
#define NOTE_G7H  (NOTE_G7 + TONE_HIGH_VOLUME)
#define NOTE_GS7H (NOTE_GS7 + TONE_HIGH_VOLUME)
#define NOTE_A7H  (NOTE_A7 + TONE_HIGH_VOLUME)
#define NOTE_AS7H (NOTE_AS7 + TONE_HIGH_VOLUME)
#define NOTE_B7H  (NOTE_B7 + TONE_HIGH_VOLUME)
#define NOTE_C8H  (NOTE_C8 + TONE_HIGH_VOLUME)
#define NOTE_CS8H (NOTE_CS8 + TONE_HIGH_VOLUME)
#define NOTE_D8H  (NOTE_D8 + TONE_HIGH_VOLUME)
#define NOTE_DS8H (NOTE_DS8 + TONE_HIGH_VOLUME)
#define NOTE_E8H  (NOTE_E8 + TONE_HIGH_VOLUME)
#define NOTE_F8H  (NOTE_F8 + TONE_HIGH_VOLUME)
#define NOTE_FS8H (NOTE_FS8 + TONE_HIGH_VOLUME)
#define NOTE_G8H  (NOTE_G8 + TONE_HIGH_VOLUME)
#define NOTE_GS8H (NOTE_GS8 + TONE_HIGH_VOLUME)
#define NOTE_A8H  (NOTE_A8 + TONE_HIGH_VOLUME)
#define NOTE_AS8H (NOTE_AS8 + TONE_HIGH_VOLUME)
#define NOTE_B8H  (NOTE_B8 + TONE_HIGH_VOLUME)
#define NOTE_C9H  (NOTE_C9 + TONE_HIGH_VOLUME)
#define NOTE_CS9H (NOTE_CS9 + TONE_HIGH_VOLUME)
#define NOTE_D9H  (NOTE_D9 + TONE_HIGH_VOLUME)
#define NOTE_DS9H (NOTE_DS9 + TONE_HIGH_VOLUME)
#define NOTE_E9H  (NOTE_E9 + TONE_HIGH_VOLUME)
#define NOTE_F9H  (NOTE_F9 + TONE_HIGH_VOLUME)
#define NOTE_FS9H (NOTE_FS9 + TONE_HIGH_VOLUME)
#define NOTE_G9H  (NOTE_G9 + TONE_HIGH_VOLUME)
#define NOTE_GS9H (NOTE_GS9 + TONE_HIGH_VOLUME)
#define NOTE_A9H  (NOTE_A9 + TONE_HIGH_VOLUME)
#define NOTE_AS9H (NOTE_AS9 + TONE_HIGH_VOLUME)
#define NOTE_B9H  (NOTE_B9 + TONE_HIGH_VOLUME)


#endif
