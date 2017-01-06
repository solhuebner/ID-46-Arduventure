#ifndef INPUTS_H
#define INPUTS_H

#include <Arduino.h>
#include "globals.h"
#include "player.h"
#include "worlddata.h"
#include "items.h"

void checkInputs()
{
  switch (gameState)
  {
    case STATE_GAME_PLAYING:
      player.walking = false;
      if (arduboy.pressed(DOWN_BUTTON) && (player.y < GAME_BOTTOM) && !getSolid(player.x + 3, player.y + 16) && !getSolid(player.x + 12, player.y + 16))
      {
        player.direction = FACING_SOUTH;
        player.y++;
        player.walking = true;
      }
      else if (arduboy.pressed(LEFT_BUTTON) && (player.x > GAME_LEFT) && !getSolid(player.x - 1, player.y + 8) && !getSolid(player.x - 1, player.y + 14))
      {
        player.direction = FACING_WEST;
        player.x--;
        player.walking = true;
      }
      else if (arduboy.pressed(UP_BUTTON) && (player.y > GAME_TOP) && !getSolid(player.x + 3, player.y + 7) && !getSolid(player.x + 12, player.y + 7))
      {
        player.direction = FACING_NORTH;
        player.y--;
        player.walking = true;
      }
      else if (arduboy.pressed(RIGHT_BUTTON) && (player.x < GAME_RIGHT) && !getSolid(player.x + 16, player.y + 8) && !getSolid(player.x + 16, player.y + 14))
      {
        player.direction = FACING_EAST;
        player.x++;
        player.walking = true;
      }
      if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_INVENTORY;
      else if (arduboy.justPressed(B_BUTTON));
      cam.x = max(player.x - 56, 0);
      cam.y = max(player.y - 24, 0);
      break;

      
    case STATE_GAME_INVENTORY:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 4)) cursorY++;
      else if (arduboy.justPressed(A_BUTTON)) gameState = STATE_GAME_PLAYING;
      else if (arduboy.justPressed(B_BUTTON))
      {
        if (cursorY == 0) gameState = STATE_GAME_ITEMS + cursorY;
        else gameState = STATE_GAME_ITEMS + cursorY - 5;
        cursorY = 0;
      }
      break;
    case STATE_GAME_EQUIP:
      if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
      else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < 2)) cursorY++;
      else if (arduboy.justPressed(A_BUTTON))
      {
        gameState = STATE_GAME_INVENTORY;
        cursorY = 1;
      }
      else if (arduboy.justPressed(B_BUTTON))
      {
        gameState = STATE_GAME_WEAPON + cursorY;
        cursorY = 0;
      }
      break;
    case STATE_GAME_STATS:
      if (arduboy.justPressed(A_BUTTON | B_BUTTON))
      {
        gameState = STATE_GAME_INVENTORY;
        cursorY = 2;
      }
      break;




    case STATE_GAME_ITEMS: case STATE_GAME_WEAPON: case STATE_GAME_ARMOR: case STATE_GAME_AMULET:
      if (!yesNo)
      {
        if (arduboy.justPressed(UP_BUTTON) && (cursorY > 0)) cursorY--;
        else if (arduboy.justPressed(DOWN_BUTTON) && (cursorY < bitCount(player.hasStuff[2 * (gameState - STATE_GAME_ITEMS)]) - 1)) cursorY++;
        else if (arduboy.justPressed(A_BUTTON))
        {
          cursorY = (gameState == STATE_GAME_ITEMS) ? 0 : (gameState - 13);
          gameState = (gameState == STATE_GAME_ITEMS) ? STATE_GAME_INVENTORY : STATE_GAME_EQUIP;
        }
        else if (arduboy.justPressed(B_BUTTON) && player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))])
        {
          question = true;
          yesNo = true;
        }
      }
      else
      {
        if (arduboy.justPressed(UP_BUTTON)) cursorYesNoY = true;
        else if (arduboy.justPressed(DOWN_BUTTON)) cursorYesNoY = false;
        else if (arduboy.justPressed(A_BUTTON))
        {
          question = false;
          yesNo = false;
          cursorYesNoY = true;
        }
        else if (arduboy.justPressed(B_BUTTON))
        {
          if (cursorYesNoY)
          {
            selectItemsEquipment();
            cursorY = 0;
          }
          question = false;
          yesNo = false;
          cursorYesNoY = true;
        }
      }
      break;

    case STATE_GAME_SAVE:
      if (arduboy.justPressed(UP_BUTTON)) cursorYesNoY = true;
      else if (arduboy.justPressed(DOWN_BUTTON)) cursorYesNoY = false;
      else if (arduboy.justPressed(A_BUTTON))
      {
        gameState = STATE_GAME_INVENTORY;
        yesNo = false;
        cursorY = 3;
        cursorYesNoY = true;
      }
      else if (arduboy.justPressed(B_BUTTON))
      {
        if (cursorYesNoY) saveGame();
        yesNo = false;
        gameState = STATE_GAME_PLAYING;
        cursorY = 0;
        cursorYesNoY = true;
      }
      break;
  }
}

#endif
