#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "globals.h"
#include "inputs.h"
#include "text.h"
#include "inventory.h"


void stateGameNew()
{
  byte alphabetX = 12;
  byte alphabetY = 16;
  arduboy.fillScreen(1);

  for (byte i = 0; i < 36; i++)
  {
    sprites.drawErase( alphabetX, alphabetY, font, i + 1);
    alphabetX += 12;
    if (alphabetX > 119)
    {
      alphabetY += 10;
      alphabetX = 12;
    }
  }

  if (arduboy.justPressed(UP_BUTTON)) cursorY += (cursorY > 0) ? -1 : 4;
  else if (arduboy.justPressed(DOWN_BUTTON)) cursorY += (cursorY < 4) ? 1 : -4;
  else if (arduboy.justPressed(LEFT_BUTTON))cursorX += (cursorX > 0) ? -1 : 8;
  else if (arduboy.justPressed(RIGHT_BUTTON)) cursorX += (cursorX < 8) ? 1 : -8;
  if (cursorY == 4) cursorX = 7;
  if (arduboy.justPressed(B_BUTTON))
  {
    byte selectedLetter = cursorX + (cursorY * 9) + 1;
    if (selectedLetter > 36)
    {
      player.name[0] = currentLetter;
      if (!currentLetter)
      {
        player.name[0] = 4;
        player.name[1] = 12;
        player.name[2] = 5;
        player.name[3] = 14;
        player.name[4] = 1;
      }
      currentLetter = 0;
      cursorX = 0;
      cursorY = 0;
      gameState = STATE_GAME_PLAYING;
      setPlayer();
      return;
    }
    else
    {
      player.name[currentLetter + 1] = selectedLetter;
      currentLetter = min(currentLetter + 1, 5);
    }
  }

  else if (arduboy.justPressed(A_BUTTON))
  {
    if (currentLetter > 0)
    {
      player.name[currentLetter] = 50;
      currentLetter--;
    }
  }

  drawSentence(3, 12, 4, BLACK, ALIGN_LEFT);
  drawName(84, 4, BLACK);
  sprites.drawErase(6 + (cursorX * 12), 16 + (cursorY * 10), font, 44);
  drawWord(9, 96, 56, BLACK, ALIGN_LEFT);
};

void showPlayField()
{
  arduboy.fillScreen(1);
  drawName(46, 12, BLACK);
  drawPlayer();
}


void stateGamePlaying()
{
  showPlayField();
  checkMapInputs();
};

void stateGameInventory()
{
  showPlayField();
  byte rectangleX = 85;
  byte rectangleY = 0;
  while(rectangleY < 64)
  {
    sprites.drawErase(rectangleX, rectangleY, font, 56);
    rectangleX += 5;
    if (rectangleX > 125)
    {
      rectangleY += 8;
      rectangleX = 85;
    }
  }
  drawSentence(4, 96, 2, WHITE, ALIGN_LEFT);
  sprites.drawSelfMasked(90, 2 + (cursorY * 12), font, 44);
  checkInventoryInputs();
};

void stateGameItems()
{

}

void stateGameStats()
{

}

void stateGameSave()
{

}

void stateGameOver()
{

};



#endif
