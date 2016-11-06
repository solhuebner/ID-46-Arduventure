#ifndef MENU_H
#define MENU_H

#include <Arduino.h>
#include "globals.h"
#include "player.h"
#include "text.h"

void stateMenuIntro()
{
  globalCounter++;
  sprites.drawSelfMasked(34, 4, T_arg, 0);
  if (globalCounter > 180) gameState = STATE_MENU_MAIN;
}

void stateMenuMain()
{
  sprites.drawSelfMasked(36, 3, aTeamArgGame, 0);
  sprites.drawSelfMasked(10, 10, titleScreen, 0);
  drawWord(1, 40, 37, WHITE, ALIGN_LEFT);
  drawSentence(0, 40, 46, WHITE, ALIGN_LEFT);
  if (arduboy.audio.enabled()) drawSentence(1, 40, 55, WHITE, ALIGN_LEFT);
  else drawSentence(2, 40, 55, WHITE, ALIGN_LEFT);
  sprites.drawSelfMasked( 32, 37 + (menuSelection - 2) * 9, font, 44);
  sprites.drawSelfMasked( 90, 37 + (menuSelection - 2) * 9, font, 45);
  
  if (arduboy.justPressed(UP_BUTTON) && (menuSelection > 2)) menuSelection--;
  else if (arduboy.justPressed(DOWN_BUTTON) && (menuSelection < 4)) menuSelection++;
  else if (arduboy.justPressed(B_BUTTON)) gameState = menuSelection;
}

void stateMenuContinue()
{
  gameState = STATE_GAME_PLAYING;
}

void stateMenuNew()
{
  setPlayer();
  gameState = STATE_GAME_NEW;
}

void stateMenuSound()
{
  if (arduboy.audio.enabled()) arduboy.audio.off();
  else arduboy.audio.on();
  arduboy.audio.saveOnOff();
  gameState = STATE_MENU_MAIN;
}


#endif
