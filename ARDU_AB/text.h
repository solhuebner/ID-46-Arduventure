#ifndef TEXT_H
#define TEXT_H

#define WORD                         0
#define SENTENCE                     1

#include <Arduino.h>
#include "globals.h"
#include "dictionary.h"

int findBegin(byte searchObject, boolean wordOrSentence)
{
  int i = 0;
  while (searchObject != 0)
  {
    if (!wordOrSentence) i += pgm_read_byte(&library[i]) + 1;
    else i += pgm_read_byte(&sentences[i]) + 1;
    searchObject--;
  }
  return i;
}

void drawWord(byte wordOfLibrary, byte x, byte y, boolean color, boolean alignment)
{
  byte xOffset = 0;
  int startWord = findBegin(wordOfLibrary, WORD);
  byte sizeWord = pgm_read_byte(&library[startWord]);
  for (int i = startWord + 1; i < startWord + 1 + sizeWord; i++)
  {
    if (color) sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeWord) * 6) : 0) + xOffset, y, font, pgm_read_byte(&library[i]));
    else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeWord) * 6) : 0) + xOffset, y, font, pgm_read_byte(&library[i]));
    xOffset += 6;
  }
}

void drawSentence(byte sentenceOfLibrary, byte x, byte y, boolean color, boolean alignment)
{
  byte yOffset = 0;
  int startSentence = findBegin(sentenceOfLibrary, SENTENCE);
  byte sizeSentence = pgm_read_byte(&sentences[startSentence]);
  byte wordSpacing = 0;
  for (int i = startSentence + 1 ; i < startSentence + 1 + sizeSentence; i++)
  {
    byte wordToDraw = pgm_read_byte(&sentences[i]);
    if (wordToDraw == NEWLINE)
    {
      yOffset += 6;
      wordSpacing = 0;
    }
    else {
      drawWord(wordToDraw, x + (6 * wordSpacing),  y + yOffset, color, alignment);
      int startWord = findBegin(wordToDraw, WORD);
      wordSpacing += pgm_read_byte(&library[startWord]);
    }
  }
}

void drawWordRam(const unsigned char *text, byte x, byte y, boolean color, byte alignment)
{
  byte xOffset = 0;
  byte sizeText = text[0] ;
  for (byte i = 1; i < sizeText + 1; i++)
  {
    if (color)sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y, font, text[i]);
    else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((sizeText - 1) * 6) : 0) + xOffset, y, font, text[i]);
    xOffset += 6;
  }
}


void drawSentenceRam(const unsigned char *text, byte x, byte y, boolean color, byte alignment)
{
  byte yOffset = 0;
  byte wordSpacing = 0;
  byte sizeSentence = text[0];
  for (byte i = 1; i < sizeSentence + 1; i++)
  {
    byte wordToDraw = text[i];
    if (wordToDraw == NEWLINE)
    {
      yOffset += 6;
      wordSpacing = 0;
    }
    else {
      drawWord(wordToDraw, x + (6 * wordSpacing),  y + yOffset, color, alignment);
      int startWord = findBegin(wordToDraw, WORD);
      wordSpacing += pgm_read_byte(&library[startWord]);
    }
  }
}

int countDigitsInInt(int number)
{
  char buf[5];
  itoa(number, buf, 10);
  return strlen(buf);
}

void drawNumbersRam(int number, byte x, byte y, boolean color, boolean alignment)
{
  char buf[5];
  itoa(number, buf, 10);
  char charLen = strlen(buf);
  for (byte i = 0; i < charLen; i++)
  {
    char digit = buf[i];
    digit -= 21;
    if (color)sprites.drawSelfMasked(x - ((alignment == ALIGN_RIGHT) ? ((charLen) * 6) : 0) + (6 * i), y, font, digit);
    else sprites.drawErase(x - ((alignment == ALIGN_RIGHT) ? ((charLen) * 6) : 0) + (6 * i), y, font, digit);
  }
}

void clearDynamicTextbox()
{
  dynamicTextbox[0] = 0;
}

void drawQuestion()
{
  drawRectangle(0, 45, 130, 64, BLACK);
  drawSentence(gameState - 1, 6, 50, WHITE, ALIGN_LEFT);
}

void drawYesNo()
{
  drawSentence(9, 106, 50, WHITE, ALIGN_LEFT);
  sprites.drawSelfMasked( 98, 50 + (6 * !cursorYesNoY), font, 44);
}

#endif
