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


PROGMEM const unsigned char library[] =
{
  //  0 :
  SPACE, END,
  //  1 : CONTINUE
  3, 15, 14, 20, 9, 14, 21, 5, END,
  //  2 : NEW
  14, 5, 23, END,
  //  3 : GAME
  7, 1, 13, 5, END,
  //  4 : SND
  19, 14, 4, END,
  //  5 : OFF
  15, 6, 6, END,
  //  6 : ON
  15, 14, END,
  //  7 : YOUR
  25, 15, 21, 18, END,
  //  8 : NAME
  14, 1, 13, 5, END,
  //  9 : END
  5, 14, 4, END,
  // 10 : WELCOME
  23, 5, 12, 3, 15, 13, 5, END,
  // 11 : TO
  20, 15, END,
  // 12 : ARDUVILLAGE
  1, 18, 4, 21, 22, 9, 12, 12, 1, 7, 5, END,
  // 13 : I
  9, END,
  // 14 : WISH
  23, 9, 19, 8, END,
  // 15 : HAD
  8, 1, 4, END,
  // 16 : A
  1, END,
  // 17 : FISHING
  6, 9, 19, 8, 9, 14, 7, END,
  // 18 : ROD
  18, 15, 4, END,
  // 19 : WHAT
  23, 8, 1, 20, END,
  // 20 : DO
  4, 15, END,
  // 21 : YOU
  25, 15, 21, END,
  // 22 : BUY
  2, 21, 25, END,
  // 23 : WOULD
  23, 15, 21, 12, 4, END,
  // 24 : LIKE
  12, 9, 11, 5, END,
  // 25 : TO
  20, 15, END,
  // 26 : SELL
  19, 5, 12, 12, END,
  // 27 : CAN
  3, 1, 14, END,
  // 28 : NOT
  5, 14, 4, END,
  // 29 : ESCAPE
  5, 19, 3, 1, 16, 5, END,
  // 30 : GOT
  7, 15, 20, END,
  // 31 : AWAY
  1, 23, 1, 25, END,
  // 32 : SAFELY
  19, 1, 6, 5, 12, 25, END,
  // 33 : YOU
  25, 15, 21, END,
  // 34 : WIN
  23, 9, 14, END,
  // 35 : SLEEP
  19, 12, 5, 5, 16, END,
  // 36 : RESTORE
  18, 5, 19, 20, 15, 18, 5, END,
  // 37 : ALL
  1, 12, 12, END,
  // 38 : HEALTH
  8, 5, 1, 12, 20, 8, END,
  // 39 : SAVE
  19, 1, 22, 5, END,
  // 40 : PROGRESS
  16, 18, 15, 7, 18, 5, 19, 19, END,
  // 41 : USE
  21, 19, 5, END,
  // 42 : EQUIP
  5, 17, 21, 9, 16, END,
  // 43 : UN
  21, 14, END,
  // 44 : LEVEL
  12, 5, 22, 5, 12, END,
  // 45 : UP
  21, 16, END,
  // 46 : THE
  20, 8, 5, END,
  // 47 : BRIDGE
  2, 18, 9, 4, 7, 5, END,
  // 48 : IS
  9, 19, END,
  // 49 : BROKEN
  2, 18, 15 , 11, 5, 14, END,
  // 50 : ENDLESS
  5, 14, 4, 12, 5, 19, 19, END,
  // 51 : WOODS
  23, 15, 15, 4, 19, END,
  // 52 : AHEAD
  1, 8, 5, 1, 4, END,
};

PROGMEM const unsigned char sentences[] =
{
  // NEW GAME
  2, SPACE, 3, END,
  // SND  OFF
  4, SPACE, SPACE, 5, END,
  // SND   ON
  4, SPACE, SPACE, SPACE, 6, END,
  // WHAT IS YOUR NAME
  7, SPACE, 8, END,
};



int findWordBegin(byte searchWord)
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

int findSentenceBegin(byte searchSentence)
{
  int i = 0;
  while (searchSentence != 0)
  {
    while (pgm_read_byte(&sentences[i]) != END)
    {
      i++;
    }
    i++;
    searchSentence--;
  }
  return i;
}

byte findWordSize(int searchSizeOfWord)
{
  byte i = 0;
  while (pgm_read_byte(&library[searchSizeOfWord + i]) != END)
  {
    i++;
  }
  return i;
}

byte findSentenceSize(int searchSizeOfSentence)
{
  byte i = 0;
  while (pgm_read_byte(&sentences[searchSizeOfSentence + i]) != END)
  {
    i++;
  }
  return i;
}

void drawWord(byte wordOfLibrary, byte x, byte y, byte color, byte alignment)
{
  byte xOffset = 0;
  byte yOffset = 0;
  int startWord = findWordBegin(wordOfLibrary);
  byte sizeWord = findWordSize(startWord);

  for (int i = startWord; i < startWord + sizeWord; i++)
  {

    if (pgm_read_byte(&library[i]) == NEWLINE)
    {
      yOffset += 6;
      xOffset = -6;
    }

    if (color) sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeWord - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(&library[i]));
    else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeWord - 1) * 6) : 0) + xOffset, y + yOffset, font, pgm_read_byte(&library[i]));

    xOffset += 6;
  }
}

void drawSentence(byte sentenceOfLibrary, byte x, byte y, byte color, byte alignement)
{
  int startSentence = findSentenceBegin(sentenceOfLibrary);
  byte sizeSentence = findSentenceSize(startSentence);
  byte sizing = 0;
  for (int i = startSentence; i < startSentence + sizeSentence; i++)
  {
    drawWord(pgm_read_byte(&sentences[i]), x + (6 * sizing),  y, color, alignement);
    int startWord = findWordBegin(pgm_read_byte(&sentences[i]));
    sizing += findWordSize(startWord);
  }
}

#endif
