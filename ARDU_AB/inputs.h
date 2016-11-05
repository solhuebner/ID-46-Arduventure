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
  if (arduboy.justPressed(UP_BUTTON)) cursorY += (cursorY > 0) ? -1 : 2;
  else if (arduboy.justPressed(DOWN_BUTTON)) cursorY += (cursorY < 2) ? 1 : -2;
  if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_PLAYING;
}


#endif
