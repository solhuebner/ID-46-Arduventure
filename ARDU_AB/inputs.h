#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>
#include "globals.h"
#include "player.h"

void checkMapInputs()
{
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

  if (arduboy.justPressed(B_BUTTON)) gameState = STATE_MENU_MAIN;
  if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
}

void checkInventoryInputs()
{
  if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
  else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 2)) cursorY++;
  
  if (arduboy.justPressed(B_BUTTON)) gameState = STATE_GAME_ITEMS + cursorY;
  else if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_PLAYING;
}

void checkItemsInputs()
{
  if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
}

void checkStatsInputs()
{
  if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
}

void checkSaveInputs()
{
  if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
}


#endif
