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
  int startWord = findWordBegin(wordOfLibrary);
  byte sizeWord = findWordSize(startWord);

  for (int i = startWord; i < startWord + sizeWord; i++)
  {

    if (color) sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeWord) * 6) : 0) + xOffset, y, font, pgm_read_byte(&library[i]));
    else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeWord) * 6) : 0) + xOffset, y, font, pgm_read_byte(&library[i]));

    xOffset += 6;
  }
}

void drawSentence(byte sentenceOfLibrary, byte x, byte y, byte color, byte alignement)
{
  byte yOffset = 0;
  int startSentence = findSentenceBegin(sentenceOfLibrary);
  byte sizeSentence = findSentenceSize(startSentence);
  byte wordSpacing = 0;
  for (int i = startSentence; i < startSentence + sizeSentence; i++)
  {
    byte wordToDraw = pgm_read_byte(&sentences[i]);
    if (wordToDraw == NEWLINE)
    {
      yOffset += 6;
      wordSpacing = 0;
    }
    else {
      drawWord(wordToDraw, x + (6 * wordSpacing),  y + yOffset, color, alignement);
      int startWord = findWordBegin(pgm_read_byte(&sentences[i]));
      wordSpacing += findWordSize(startWord);
    }
  }
}

void drawWordRam(byte x, byte y, byte color)
{
  byte xOffset = 0;
  byte sizeText = player.name[0] ;

  for (byte i = 1; i < sizeText + 1; i++)
  {
    if (color)sprites.drawSelfMasked(x + xOffset, y, font, player.name[i]);
    else sprites.drawErase(x + xOffset, y, font, player.name[i]);
    xOffset += 6;
  }
}

void drawSentenceRam()
{
  
}

#endif
