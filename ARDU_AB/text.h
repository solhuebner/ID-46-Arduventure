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
#define TEXT_NEW                      1
#define TEXT_GAME                     2
#define TEXT_SND                      3
#define TEXT_OFF                      4
#define TEXT_ON                       5
#define TEXT_YOUR                     6
#define TEXT_NAME                     7
#define TEXT_END                      8

PROGMEM const unsigned char library[] =
{
  // CONTINUE
  8, 3, 15, 14, 20, 9, 14, 21, 5, END,
  // NEW
  3, 14, 5, 23, END,
  // GAME
  4, 7, 1, 13, 5, END,
  // SND
  3, 19, 14, 4, END,
  // OFF
  3, 15, 6, 6, END,
  // ON
  2, 15, 14, END,
  // YOUR
  4, 25, 15, 21, 18, END,
  // NAME
  4, 14, 1, 13, 5, END,
  // END
  3, 5, 14, 3, END,
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
  byte sizeText = pgm_read_byte(&library[startText]);

  for (int i = startText + 1; i < startText + sizeText + 1; i++)
  {

    if (pgm_read_byte(&library[i]) == NEWLINE)
    {
      yOffset += 6;
      xOffset = -6;
    }

    if (color) sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(&library[i]));
    else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(&library[i]));

    xOffset += 6;
  }
}

#endif
