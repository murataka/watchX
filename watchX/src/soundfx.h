#ifndef SOUNDFX_H
#define SOUNDFX_H
#include <Tones.h>
extern Tones sound;
extern bool soundenabled;


void buttonFX(uint16_t tone=1200);
bool outEnabled();

#endif
