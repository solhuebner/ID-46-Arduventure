#ifndef TEXT_H
#define TEXT_H

#include <Arduino.h>
#include "globals.h"

#define NONE                          255
#define NEWLINE                       254
#define ALIGN_LEFT                    0
#define ALIGN_RIGHT                   1
#define RAM                           0
#define ROM                           1

#define TEXT_CONTINUE                 0
#define TEXT_NEW_GAME                 1
#define TEXT_SND__OFF                 2
#define TEXT_SND___ON                 3
#define TEXT_YOUR_NAME                4
#define TEXT_END                      5

PROGMEM const unsigned char textContinue[] = {2, 14, 13, 19, 8, 13, 20, 4};
PROGMEM const unsigned char textNewGame[] = {13, 4, 22, NONE, 6, 0, 12, 4};
PROGMEM const unsigned char textSndOff[] = {18, 13, 3, NONE, NONE, 14, 5, 5};
PROGMEM const unsigned char textSndOn[] = {18, 13, 3, NONE, NONE, NONE, 14, 13};
PROGMEM const unsigned char textYourName[] = {24, 14, 20, 17, NONE, 13, 0, 12, 4, 41};
PROGMEM const unsigned char textEnd[] = {4, 13, 3};

struct some_entry {
  byte sizes;
  const unsigned char *ptr;
};

PROGMEM const some_entry library[] =
{
  {8, textContinue},
  {8, textNewGame},
  {8, textSndOff},
  {8, textSndOn},
  {10, textYourName},
  {3, textEnd},
};



void drawText(byte wordOfLibrary, byte x, byte y, byte color, byte alignment)
{
  byte xOffset = 0;
  byte yOffset = 0;
  byte sizeText = library[wordOfLibrary].sizes;
  const unsigned char *text = pgm_read_byte(&library[wordOfLibrary].ptr);
  Serial.println(sizeText);

  for (byte i = 0; i < sizeText; i++)
  {
    if (pgm_read_byte(text) == NEWLINE)
    {
      yOffset += 6;
      xOffset = -6;
    }
    else if (pgm_read_byte(text) != NONE)
    {
      if (color) sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(text));
      else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(text));
    }
    xOffset += 6;
    text++;
  }
}

void drawName(const unsigned char *text, byte x, byte y, byte color, byte alignment)
{
  byte xOffset = 0;
  byte yOffset = 0;
  byte sizeText = text[0] ;

  for (byte i = 1; i < sizeText + 1; i++)
  {
    if ((text[i]) == NEWLINE)
    {
      yOffset += 6;
      xOffset = -6;
    }
    else if ((text[i]) != NONE)
    {
      if (color)sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, text[i]);
      if (!color)sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, text[i]);
    }
    xOffset += 6;
  }
}


#endif
