#ifndef TEXT_H
#define TEXT_H

#include <Arduino.h>
#include "globals.h"
#include "dictionary.h"


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
