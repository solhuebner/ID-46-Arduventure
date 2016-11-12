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
      else if (arduboy.justPressed(B_BUTTON));
      break;
    case STATE_GAME_INVENTORY:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 4)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_PLAYING;
      else if (arduboy.justPressed(B_BUTTON)) gameState = STATE_GAME_ITEMS + cursorY;
      break;
    case STATE_GAME_EQUIP:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 2)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      else if (arduboy.justPressed(B_BUTTON)) gameState = STATE_GAME_WEAPON + cursorY;
      break;

    case STATE_GAME_ITEMS:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < bitCount(player.hasStuff[0]) - 1)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      break;
    case STATE_GAME_WEAPON:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < bitCount(player.hasStuff[2]) - 1)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_EQUIP;
      break;
    case STATE_GAME_ARMOR:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < bitCount(player.hasStuff[4]) - 1)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_EQUIP;
      break;
    case STATE_GAME_AMULET:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < bitCount(player.hasStuff[6]) - 1)) cursorY++;
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_EQUIP;
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


#endif
