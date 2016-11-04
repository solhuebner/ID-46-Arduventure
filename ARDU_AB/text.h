#ifndef TEXT_H
#define TEXT_H

#include <Arduino.h>
#include "globals.h"

#define SPACE                         0
#define NEWLINE                       254
#define END                           255
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

PROGMEM const unsigned char library[] =
{
  // CONTINUE
  8, 3, 15, 14, 20, 9, 14, 21, 5, END,
  // NEW GAME
  8, 14, 5, 23, SPACE, 7, 1, 13, 5, END,
  // SND  OFF
  8, 19, 14, 4, SPACE, SPACE, 15, 6, 6, END,
  // SND   ON
  8, 19, 14, 4, SPACE, SPACE, SPACE, 15, 14, END,
  // YOUR NAME
  10, 25, 15, 21, 18, SPACE, 14, 1, 13, 5, 42, END,
  // END
  3, 5, 14, 4, END,
};

int findStart(byte searchWord)
{
  int i = 0;
  while (searchWord != 0)
  {
    while (pgm_read_byte(&library[i]) != END)
    {
      i++;
    }
    i++;
    searchWord--;
  }
  return i;
}

void drawText(byte wordOfLibrary, byte x, byte y, byte color, byte alignment)
{
  byte xOffset = 0;
  byte yOffset = 0;
  int startText = findStart(wordOfLibrary);
  byte sizeText = pgm_read_byte(&library[findStart(wordOfLibrary)]);
  //Serial.print(startText);
  //Serial.print(" : ");
  //Serial.println(sizeText);

  for (int i = startText+1; i < startText + sizeText+1; i++)
  {
    
    if (pgm_read_byte(&library[i]) == NEWLINE)
    {
      yOffset += 6;
      xOffset = -6;
    }
    
    if (pgm_read_byte(&library[i]) != SPACE)
    {
      if (color) sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(&library[i]));
      else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(&library[i]));
    }
    xOffset += 6;
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
    else if ((text[i]) != SPACE)
    {
      if (color)sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, text[i]);
      if (!color)sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, text[i]);
    }
    xOffset += 6;
  }
}


#endif
