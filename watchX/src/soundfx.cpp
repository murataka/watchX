#include <soundfx.h>

bool soundenabled=false;
bool outEnabled(){

  return soundenabled;
}

Tones sound(outEnabled);
void buttonFX(uint16_t tone){

sound.tone(tone, 100,tone+300,50);

}
