#ifndef OLED_H
#define OLED_H




/** SSD1306 LCD driver commands */

#define     SSD1306_SETLOWCOLUMN      0x00
#define     SSD1306_SETHIGHCOLUMN     0x10
#define    SSD1306_MEMORYMODE        0x20
#define    SSD1306_COLUMNADDR        0x21
#define    SSD1306_PAGEADDR          0x22
#define    SSD1306_SETSTARTLINE      0x40
#define    SSD1306_DEFAULT_ADDRESS   0x78
#define    SSD1306_SETCONTRAST       0x81
#define    SSD1306_CHARGEPUMP        0x8D
#define    SSD1306_SEGREMAP          0xA0
#define    SSD1306_DISPLAYALLON_RESUME  0xA4
#define    SSD1306_DISPLAYALLON      0xA5
#define    SSD1306_NORMALDISPLAY     0xA6
#define    SSD1306_INVERTDISPLAY     0xA7
#define    SSD1306_SETMULTIPLEX      0xA8
#define    SSD1306_DISPLAYOFF        0xAE
#define    SSD1306_DISPLAYON         0xAF
#define    SSD1306_SETPAGE           0xB0
#define    SSD1306_COMSCANINC        0xC0
#define    SSD1306_COMSCANDEC        0xC8
#define    SSD1306_SETDISPLAYOFFSET  0xD3
#define    SSD1306_SETDISPLAYCLOCKDIV  0xD5
#define    SSD1306_SETPRECHARGE      0xD9
#define    SSD1306_SETCOMPINS        0xDA
#define    SSD1306_SETVCOMDETECT     0xDB
#define    SSD1306_SWITCHCAPVCC      0x02
#define    SSD1306_NOP               0xE3

/** SSD1306 supported memory modes. */

#define    HORIZONTAL_ADDRESSING_MODE   0x00
#define    VERTICAL_ADDRESSING_MODE     0x01
#define    PAGE_ADDRESSING_MODE         0x02

  #define cesPin A5
  #define dcPin A3

  #define rstPin A4
#define s_displayWidth 128
#define s_displayHeight 64



// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A



 #define FRAME_WIDTH     128
#define FRAME_HEIGHT    64

 // Quick and easy macro for a for loop
#define LOOP(count, var) for(byte var=0;var<count;var++)

// Reverse loop sometimes produces smaller/faster code
#define LOOPR(count, var) for(byte var=count;var--;)

#define CONCAT(a, b) a ## b

#define uint unsigned int
//#define byte unsigned char
extern   unsigned char mbuf[1024];

extern uint8_t uiX,uiY;
extern unsigned char animation_offsetY;
void ssd1306_drawBuffer(byte x, byte y, byte w, byte h, const byte *buf);
void drawString(uint8_t x,uint8_t y,const char*s,const byte* font,char startindex=-32);
void drawString_P(uint8_t x,uint8_t y,const byte*s,const byte* font,char startindex=-32);

void ssd1306_sendCommand(uint8_t command);
void ssd1306_configure();
void draw_bitmap(byte x, byte yy, const byte* bitmap, byte w, byte h, bool invert=false, byte offsetY=0);
 byte readPixels(const byte* loc, bool invert);
 void ssd1306_spiStop_hw();
void ssd1306_spiCommandStart();
 void ssd1306_spiDataStart();
 void clearAll();
 void drawLine( uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2);
 void drawPixel(uint8_t x, uint8_t y,char color=1);

#endif
