#ifndef GAME_H
#define GAME_H

#include <Arduino.h>
#include "globals.h"
#include "inputs.h"
#include "inventory.h"
#include "items.h"


void stateGameNew()
{
  arduboy.fillScreen(1);
  byte alphabetX = 12;
  byte alphabetY = 16;
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
  drawWordRam(player.name, 84, 4, BLACK, ALIGN_LEFT);
  sprites.drawErase(6 + (cursorX * 12), 16 + (cursorY * 10), font, 44);
  drawWord(9, 96, 56, BLACK, ALIGN_LEFT);
};

void showPlayField()
{
  arduboy.fillScreen(1);
  drawWordRam(player.name, 46, 12, BLACK, ALIGN_LEFT);
  drawPlayer();
}


void stateGamePlaying()
{
  showPlayField();
  checkInputs();
};

void stateGameInventory()
{
  showPlayField();
  drawRectangle(83, 0, 130, 64, BLACK);
  drawSentence(4, 93, 2, WHITE, ALIGN_LEFT);
  sprites.drawSelfMasked(86, 2 + (cursorY * 12), font, 44);
  checkInputs();
};

void stateGameItems()
{
  getItems();
  drawWord(83, 6, 2, WHITE, ALIGN_LEFT);
  drawRectangle(0, 10, 130, 48, WHITE);
  drawSentenceRam(dynamicTextbox, 6, 14, BLACK, ALIGN_LEFT);
  checkInputs();
}

void stateGameEquip()
{
  showPlayField();
  drawRectangle(83, 0, 130, 64, BLACK);
  drawSentence(10, 93, 2, WHITE, ALIGN_LEFT);
  sprites.drawSelfMasked(86, 2 + (cursorY * 12), font, 44);
  checkInputs();
}

void stateGameStats()
{
  drawPlayerStats();
  checkInputs();
}

void stateGameSave()
{
  showPlayField();
  drawRectangle(0, 48, 130, 64, BLACK);
  drawSentence(5, 6, 50, WHITE, ALIGN_LEFT);
  drawYesNo ();
  checkInputs();
}

void stateGameEnd()
{
  gameState = STATE_MENU_MAIN;
}

void stateGameWeapon()
{
  showPlayField();
  drawRectangle(85, 0, 130, 64, BLACK);
  checkInputs();
}
void stateGameArmor()
{
  showPlayField();
  drawRectangle(85, 0, 130, 64, BLACK);
  checkInputs();
}
void stateGameExtra()
{
  showPlayField();
  drawRectangle(85, 0, 130, 64, BLACK);
  checkInputs();
}


void stateGameOver()
{

};



#endif
