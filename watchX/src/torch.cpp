#include "watchX.h"
#include "torch.h"
#include "oled.h"

#include "temperature.h"



void drawTorch(){

for(uint16_t a=0;a<1024;a++)
mbuf[a]=0xff;
//drawString(16,0,"< TORCH >",smallFont);
digitalWrite(13,HIGH);
digitalWrite(6,HIGH);



}
