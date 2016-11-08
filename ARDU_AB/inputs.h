#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>
#include "globals.h"
#include "player.h"

void checkInputs()
{
  switch (gameState)
  {
    case STATE_GAME_PLAYING:
      player.walking = false;
      if (arduboy.pressed(DOWN_BUTTON) && (player.y < GAME_BOTTOM))
      {
        player.direction = FACING_SOUTH;
        player.y++;
        player.walking = true;
      }
      else if (arduboy.pressed(LEFT_BUTTON) && (player.x > GAME_LEFT))
      {
        player.direction = FACING_WEST;
        player.x--;
        player.walking = true;
      }
      else if (arduboy.pressed(UP_BUTTON) && (player.y > GAME_TOP))
      {
        player.direction = FACING_NORTH;
        player.y--;
        player.walking = true;
      }
      else if (arduboy.pressed(RIGHT_BUTTON) && (player.x < GAME_RIGHT))
      {
        player.direction = FACING_EAST;
        player.x++;
        player.walking = true;
      }
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      else if (arduboy.justPressed(B_BUTTON)) gameState = STATE_MENU_MAIN;
      break;
    case STATE_GAME_INVENTORY:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 3)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_PLAYING;
      else if (arduboy.justPressed(B_BUTTON)) gameState = STATE_GAME_ITEMS + cursorY;
      break;
    case STATE_GAME_ITEMS:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 2)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      break;
    case STATE_GAME_EQUIP:
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      break;
    case STATE_GAME_STATS:
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      else if (arduboy.justPressed(B_BUTTON)) gameState = STATE_GAME_PLAYING;
      break;
    case STATE_GAME_SAVE:
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      else if (arduboy.justPressed(B_BUTTON))
      {
        if (!cursorY) saveGame();
        gameState = STATE_GAME_PLAYING;
      }
      break;
  }
  if (gameStatePrevious != gameState)
  {
    gameStatePrevious = gameState;
    cursorY = 0;
    cursorX = 0;
  }
}

void drawYesNo ()
{
  drawRectangle(95, 32, 130, 48, BLACK);
  drawSentence(9, 106, 34, WHITE, ALIGN_LEFT);
  if (arduboy.justPressed(UP_BUTTON)) cursorY = 0;
  else if (arduboy.justPressed(DOWN_BUTTON)) cursorY = 1;
  sprites.drawSelfMasked( 98, 34 + (6 * cursorY), font, 44);
}


#endif
