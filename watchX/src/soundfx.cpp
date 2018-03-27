#include <soundfx.h>

bool soundenabled=false;
bool outEnabled(){

  return soundenabled;
}

Tones sound(outEnabled);
void buttonFX(uint16_t tone=1200){

sound.tone(tone, 100);

}
