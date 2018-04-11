#include <soundfx.h>


bool outEnabled(){

  return true;
}

Tones sound(outEnabled);
void buttonFX(uint16_t tone){

sound.tone(tone, 100,tone+300,50);

}
