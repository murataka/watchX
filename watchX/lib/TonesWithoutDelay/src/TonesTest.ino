// Forked from the ArduboyTones library


#include <Tones.h>

bool outEnabled(){

  return true;
}
Tones sound(outEnabled);

#define BUTTON_DELAY 200
 
#define NDUR 100

const uint16_t sound1[] PROGMEM = {
  NOTE_C1,500, NOTE_C1H,500, NOTE_G1,500, NOTE_G1H,500,
  NOTE_C2,500, NOTE_C2H,500, NOTE_G2,500, NOTE_G2H,500,
  NOTE_C3,500, NOTE_C3H,500, NOTE_G3,500, NOTE_G3H,500,
  NOTE_C4,500, NOTE_C4H,500, NOTE_G4,500, NOTE_G4H,500,
  NOTE_C5,500, NOTE_C5H,500, NOTE_G5,500, NOTE_G5H,500,
  NOTE_C6,500, NOTE_C6H,500, NOTE_G6,500, NOTE_G6H,500,
  NOTE_C7,500, NOTE_C7H,500, NOTE_G7,500, NOTE_G7H,500,
  NOTE_C8,500, NOTE_C8H,500, NOTE_G8,500, NOTE_G8H,500,
  NOTE_C9,500, NOTE_C9H,500, NOTE_G9,500, NOTE_G9H,500,
  TONES_END
};



void loop() {







/*
  newNotes = false;
  inRAM[34] = inRAM[38] = NOTE_D5H;
  sound.tonesInRAM(inRAM);
  arduboy.clear();
  arduboy.print("tonesInRAM(inRAM)\n\nA: change notes\nB: break");
  while (sound.playing()) {
    moveCircle();
    if (arduboy.pressed(A_BUTTON)) {
      newNotes = !newNotes;
      if (newNotes) {
        inRAM[34] = inRAM[38] = NOTE_C5H;
      }
      else {
        inRAM[34] = inRAM[38] = NOTE_D5H;
      }
      delay(BUTTON_DELAY);
    }
    if (arduboy.pressed(B_BUTTON)) {
      delay(BUTTON_DELAY);
      break;
    }
  }

  sound.tones(sound1);
  arduboy.clear();
  arduboy.print("volumeMode(IN_TONES)\ntones(sound1)\n\nB: break");
  while(sound.playing()) {
    moveCircle();
    if (arduboy.pressed(B_BUTTON)) {
      delay(BUTTON_DELAY);
      break;
    }
  }

  sound.volumeMode(VOLUME_ALWAYS_NORMAL);
  sound.tones(sound1);
  arduboy.clear();
  arduboy.print("volumeMode(NORMAL)\ntones(sound1)\n\nB: noTone(), break");
  while(sound.playing()) {
    moveCircle();
    if (arduboy.pressed(B_BUTTON)) {
      sound.noTone();
      delay(BUTTON_DELAY);
      break;
    }
  }

  sound.volumeMode(VOLUME_ALWAYS_HIGH);
  sound.tones(sound1);
  arduboy.clear();
  arduboy.print("volumeMode(HIGH)\ntones(sound1)\n\nB: break");
  while(sound.playing()) {
    moveCircle();
    if (arduboy.pressed(B_BUTTON)) {
      delay(BUTTON_DELAY);
      break;
    }
  }
  sound.volumeMode(VOLUME_IN_TONE);
  */
}



void setup(){
  uint16_t inRAM[] = {
    NOTE_E4,400, NOTE_D4,200, NOTE_C4,400, NOTE_REST,200, NOTE_D4,200,
    NOTE_C4,300, NOTE_REST,100, NOTE_C4,300, NOTE_REST,100, NOTE_E4,300,
    NOTE_REST,100, NOTE_G4,300, NOTE_REST,100, NOTE_F4,300, NOTE_REST,100,
    NOTE_A4,300, NOTE_REST,100, NOTE_D5H,200, NOTE_REST,200, NOTE_D5H,200,
    NOTE_REST,1500,
    TONES_END
  };


  sound.tonesInRAM(inRAM);

  while (sound.playing()) {

  }
  const uint16_t allNotes[] PROGMEM = {
    NOTE_C0H,NDUR, NOTE_CS0,NDUR, NOTE_D0,NDUR, NOTE_DS0,NDUR, NOTE_E0,NDUR, NOTE_F0,NDUR,
    NOTE_FS0,NDUR, NOTE_G0,NDUR, NOTE_GS0,NDUR, NOTE_A0,NDUR, NOTE_AS0,NDUR, NOTE_B0,NDUR,
    NOTE_C1H,NDUR, NOTE_CS1,NDUR, NOTE_D1,NDUR, NOTE_DS1,NDUR, NOTE_E1,NDUR, NOTE_F1,NDUR,
    NOTE_FS1,NDUR, NOTE_G1,NDUR, NOTE_GS1,NDUR, NOTE_A1,NDUR, NOTE_AS1,NDUR, NOTE_B1,NDUR,
    NOTE_C2H,NDUR, NOTE_CS2,NDUR, NOTE_D2,NDUR, NOTE_DS2,NDUR, NOTE_E2,NDUR, NOTE_F2,NDUR,
    NOTE_FS2,NDUR, NOTE_G2,NDUR, NOTE_GS2,NDUR, NOTE_A2,NDUR, NOTE_AS2,NDUR, NOTE_B2,NDUR,
    NOTE_C3H,NDUR, NOTE_CS3,NDUR, NOTE_D3,NDUR, NOTE_DS3,NDUR, NOTE_E3,NDUR, NOTE_F3,NDUR,
    NOTE_FS3,NDUR, NOTE_G3,NDUR, NOTE_GS3,NDUR, NOTE_A3,NDUR, NOTE_AS3,NDUR, NOTE_B3,NDUR,
    NOTE_C4H,NDUR, NOTE_CS4,NDUR, NOTE_D4,NDUR, NOTE_DS4,NDUR, NOTE_E4,NDUR, NOTE_F4,NDUR,
    NOTE_FS4,NDUR, NOTE_G4,NDUR, NOTE_GS4,NDUR, NOTE_A4,NDUR, NOTE_AS4,NDUR, NOTE_B4,NDUR,
    NOTE_C5H,NDUR, NOTE_CS5,NDUR, NOTE_D5,NDUR, NOTE_DS5,NDUR, NOTE_E5,NDUR, NOTE_F5,NDUR,
    NOTE_FS5,NDUR, NOTE_G5,NDUR, NOTE_GS5,NDUR, NOTE_A5,NDUR, NOTE_AS5,NDUR, NOTE_B5,NDUR,
    NOTE_C6H,NDUR, NOTE_CS6,NDUR, NOTE_D6,NDUR, NOTE_DS6,NDUR, NOTE_E6,NDUR, NOTE_F6,NDUR,
    NOTE_FS6,NDUR, NOTE_G6,NDUR, NOTE_GS6,NDUR, NOTE_A6,NDUR, NOTE_AS6,NDUR, NOTE_B6,NDUR,
    NOTE_C7H,NDUR, NOTE_CS7,NDUR, NOTE_D7,NDUR, NOTE_DS7,NDUR, NOTE_E7,NDUR, NOTE_F7,NDUR,
    NOTE_FS7,NDUR, NOTE_G7,NDUR, NOTE_GS7,NDUR, NOTE_A7,NDUR, NOTE_AS7,NDUR, NOTE_B7,NDUR,
    NOTE_C8H,NDUR, NOTE_CS8,NDUR, NOTE_D8,NDUR, NOTE_DS8,NDUR, NOTE_E8,NDUR, NOTE_F8,NDUR,
    NOTE_FS8,NDUR, NOTE_G8,NDUR, NOTE_GS8,NDUR, NOTE_A8,NDUR, NOTE_AS8,NDUR, NOTE_B8,NDUR,
    NOTE_C9H,NDUR, NOTE_CS9,NDUR, NOTE_D9,NDUR, NOTE_DS9,NDUR, NOTE_E9,NDUR, NOTE_F9,NDUR,
    NOTE_FS9,NDUR, NOTE_G9,NDUR, NOTE_GS9,NDUR, NOTE_A9,NDUR, NOTE_AS9,NDUR, NOTE_B9,NDUR,
    TONES_END
  };
  sound.tonesInRAM(allNotes);
  while (sound.playing()) {

  }

}
