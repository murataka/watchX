#include <Arduino.h>
#include "oled.h"
#include <SPI.h>
 unsigned char animation_offsetY=0;
uint8_t uiX,uiY;

/// TODO global left right position setting
void ssd1306_configure(){

    const uint8_t  s_oled128x64_initData[] =
 {
     SSD1306_DISPLAYOFF, // display off
     SSD1306_MEMORYMODE, HORIZONTAL_ADDRESSING_MODE, // Page Addressing mode
     SSD1306_COMSCANDEC,             // Scan from 127 to 0 (Reverse scan)
     SSD1306_SETSTARTLINE | 0x00,    // First line to start scanning from
     SSD1306_SETCONTRAST, 0x7F,      // contast value to 0x7F according to datasheet
     SSD1306_SEGREMAP | 0x01,        // Use reverse mapping. 0x00 - is normal mapping
    SSD1306_NORMALDISPLAY,
     SSD1306_SETMULTIPLEX, 63,       // Reset to default MUX. See datasheet
     SSD1306_SETDISPLAYOFFSET, 0x00, // no offset
     SSD1306_SETDISPLAYCLOCKDIV, 0x80,// set to default ratio/osc frequency
     SSD1306_SETPRECHARGE, 0xF1,     // switch precharge to 0x22 // 0xF1
     SSD1306_SETCOMPINS, 0x12,       // set divide ratio
     SSD1306_SETVCOMDETECT, 0x40,    // vcom deselect to 0x20 // 0x40
     SSD1306_CHARGEPUMP, 0x14,       // Enable charge pump
    // 0X20,0X80,
     SSD1306_DISPLAYALLON_RESUME,
     SSD1306_DISPLAYON
 };

for( uint8_t i=0; i<sizeof(s_oled128x64_initData); i++)
{
  ssd1306_sendCommand(s_oled128x64_initData[i]);
}

}
 void ssd1306_drawBuffer(byte x, byte y, byte w, byte h, const byte *buf)
{

    uint8_t i, j;
    // ssd1306_setRamBlock(x, y, w);
    ssd1306_spiDataStart();
    for(j=(h >> 3); j>0; j--)
    {
        for(i=w;i>0;i--)
        {
        //  ssd1306_sendPixels(0xFF);
            SPI.transfer(*buf++);
        }
   //     ssd1306_nextRamPage();
    }
    ssd1306_spiStop_hw();

}

void ssd1306_sendCommand(uint8_t command)
{
    ssd1306_spiCommandStart();
    SPI.transfer(command);
    ssd1306_spiStop_hw();
}

void ssd1306_sendData(uint8_t data)
{
    ssd1306_spiDataStart();
   SPI.transfer(data);
    ssd1306_spiStop_hw();
}


 void ssd1306_spiStop_hw()
{

        digitalWrite(cesPin, HIGH);

    SPI.endTransaction();
}

  static void ssd1306_spiStart_hw()
{
  ///20000000 ////4000000
    SPI.beginTransaction(SPISettings(20000000, MSBFIRST, SPI_MODE0));

        digitalWrite(cesPin,LOW);

}

void clearAll(){
//if(animation_offsetY==0)
  memset(mbuf, 0x00, 128*8);
}

void drawString(uint8_t x,uint8_t y,const char*s,const byte* font,char startindex){
char a=0;
if(!s)return;
  while(s[a]!=0){
  //  strtmpbuf[a]= pgm_read_byte_near(months[month]+a);
//  draw_bitmap( 0, 32, font_mid, 19, 24, false, 0);

     draw_bitmap( x+(a*6),  y, font+((s[a]+startindex)*5), 5, 8, false, 0);
     a++;
  }

}
void drawLine( uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
  uint8_t tmp;
  uint8_t x,y;
  uint8_t dx, dy;
  int8_t err;
  int8_t ystep;

  uint8_t swapxy = 0;
//y1+=animation_offsetY;
//y2+=animation_offsetY;
  /* no intersection check at the moment, should be added... */

  if ( x1 > x2 ) dx = x1-x2; else dx = x2-x1;
  if ( y1 > y2 ) dy = y1-y2; else dy = y2-y1;

  if ( dy > dx )
  {
    swapxy = 1;
    tmp = dx; dx =dy; dy = tmp;
    tmp = x1; x1 =y1; y1 = tmp;
    tmp = x2; x2 =y2; y2 = tmp;
  }
  if ( x1 > x2 )
  {
    tmp = x1; x1 =x2; x2 = tmp;
    tmp = y1; y1 =y2; y2 = tmp;
  }
  err = dx >> 1;
  if ( y2 > y1 ) ystep = 1; else ystep = -1;
  y = y1;


  if ( x2 == 255 )
    x2--;


  for( x = x1; x <= x2; x++ )
  {
    if ( swapxy == 0 )
      drawPixel( x, y);
    else
      drawPixel( y, x);
    err -= (uint8_t)dy;
    if ( err < 0 )
    {
      y += (uint8_t)ystep;
      err += (uint8_t)dx;
    }
  }
}

void drawPixel(uint8_t x, uint8_t y,char color=1) {
  y=y+animation_offsetY;
  if(y<64)
mbuf[(y/8)*128 +x]|=1<<y%8;
}

void ssd1306_spiCommandStart()
{
    digitalWrite(dcPin, LOW);
    ssd1306_spiStart_hw();
}




/*

static void ssd1306_setBlock(uint8_t x, uint8_t y, uint8_t w)
{
    ssd1306_spiCommandStart();
    SPI.transfer(0x21); //SSD1306_COLUMNADDR
    SPI.transfer(x);
    //ssd1306_sendByte(w ? (x + w - 1) : (s_displayWidth - 1));
    SPI.transfer (x + w - 1) ;
    SPI.transfer(0x22); // SSD1306_PAGEADDR
    SPI.transfer(y);
    SPI.transfer((s_displayHeight >> 3) - 1);
    ssd1306_spiStop_hw();
}
*/
void ssd1306_spiDataStart()
{
    digitalWrite(dcPin, HIGH);
    ssd1306_spiStart_hw();
}




  byte readPixels(const byte* loc, bool invert)
{
  byte pixels = pgm_read_byte(loc);
  if(invert)
    pixels = ~pixels;
  return pixels;
}

void draw_bitmap(byte x, byte yy, const byte* bitmap, byte w, byte h, bool invert, byte offsetY)
{
  // Apply animation offset
  yy += animation_offsetY;

  //
  byte y = yy - offsetY;

  //
  byte h2 = h / 8;

  //
  byte pixelOffset = (y % 8);

  byte thing3 = (yy+h);

  //
  LOOP(h2, hh)
  {
    //
    byte hhh = (hh * 8) + y; // Current Y pos (every 8 pixels)
    byte hhhh = hhh + 8; // Y pos at end of pixel column (8 pixels)

    //
    if(offsetY && (hhhh < yy || hhhh > FRAME_HEIGHT || hhh > thing3))
      continue;

    //
    byte offsetMask = 0xFF;
    if(offsetY)
    {
      if(hhh < yy)
        offsetMask = (0xFF<<(yy-hhh));
      else if(hhhh > thing3)
        offsetMask = (0xFF>>(hhhh-thing3));
    }

    uint aa = ((hhh / 8) * FRAME_WIDTH);

    const byte* b = bitmap + (hh*w);

    // If() outside of loop makes it faster (doesn't have to keep re-evaluating it)
    // Downside is code duplication
    if(!pixelOffset && hhh < FRAME_HEIGHT)
    {
      //
      LOOP(w, ww)
      {
        // Workout X co-ordinate in frame buffer to place next 8 pixels
        byte xx = ww + x;

        // Stop if X co-ordinate is outside the frame
        if(xx >= FRAME_WIDTH)
          continue;

        // Read pixels
        byte pixels = readPixels(b + ww, invert) & offsetMask;

        mbuf[xx + aa] |= pixels;

        //setBuffByte(buff, xx, hhh, pixels, colour);
      }
    }
    else
    {
      uint aaa = ((hhhh / 8) * FRAME_WIDTH);

      //
      LOOP(w, ww)
      {
        // Workout X co-ordinate in frame buffer to place next 8 pixels
        byte xx = ww + x;

        // Stop if X co-ordinate is outside the frame
        if(xx >= FRAME_WIDTH)
          continue;

        // Read pixels
        byte pixels = readPixels(b + ww, invert) & offsetMask;

        //
        if(hhh < FRAME_HEIGHT)
          mbuf[xx + aa] |= pixels << pixelOffset;
          //setBuffByte(buff, xx, hhh, pixels << pixelOffset, colour);

        //
        if(hhhh < FRAME_HEIGHT)
          mbuf[xx + aaa] |= pixels >> (8 - pixelOffset);
          //setBuffByte(buff, xx, hhhh, pixels >> (8 - pixelOffset), colour);
      }
    }
  }
}
