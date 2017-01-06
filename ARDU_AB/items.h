#ifndef ITEMS_H
#define ITEMS_H

#include <Arduino.h>
#include "globals.h"
#include "text.h"

#define ITEM_APPLE                    0
#define ITEM_CIDER                    1
#define ITEM_ANISE                    2
#define ITEM_ABSINTH                  3
#define ITEM_RUBY                     4
#define ITEM_SAPPHIR                  5
#define ITEM_EMERALD                  6
#define ITEM_DIAMOND                  7

#define WEAPON_SLING                  0
#define WEAPON_KNIFE                  1
#define WEAPON_RAPIER                 2
#define WEAPON_SWORD                  3
#define WEAPON_AXE                    4
#define WEAPON_LANCE                  5
#define WEAPON_SPEAR                  6
#define WEAPON_BOW                    7

#define AMULET_HEALTH                 0
#define AMULET_MAGIC                  1
#define AMULET_SPEED                  2
#define AMULET_LUCK                   3
#define AMULET_GOLD                   4
#define AMULET_CLOAK                  5
#define AMULET_ESCAPE                 6
#define AMULET_RUBY                   7


void drawList()
{
  byte dynamicTextBoxSize = 0;
  byte AmountOfObjectsShown = 0;
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))], i))
    {
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = 97 + (8 * (gameState - STATE_GAME_ITEMS)) + i;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = NEWLINE;

      if (gameState == STATE_GAME_ITEMS)
      {
        sprites.drawErase(92, 3 + (3 * dynamicTextBoxSize), font, 24);
        drawNumbersRam(player.itemsAmount[i], 116 , 3 + (3 * dynamicTextBoxSize), BLACK, ALIGN_RIGHT);
      }
      else if (bitRead(player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS)) + 1], i))
      {
        drawWord(81, 68, 3 + (3 * dynamicTextBoxSize), BLACK, ALIGN_LEFT);
      }
      
      if (bitRead (player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))], i)) AmountOfObjectsShown++;
      if (AmountOfObjectsShown - 1 == cursorY) drawSentence( 19 + (8 * (gameState - STATE_GAME_ITEMS)) + i, 6, 59, WHITE, ALIGN_LEFT);
      
    }
  }
  if (!player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))])
  {
    drawSentence(gameState + 3, 34, 29, BLACK, ALIGN_LEFT);
  }
  dynamicTextbox[0] = dynamicTextBoxSize;
  drawSentenceRam(dynamicTextbox, 12, 9, BLACK, ALIGN_LEFT);
}

void selectItemsEquipment()
{
  // set the equipped flag or item used flag
  player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS)) + 1] = 0;
  // because the list is dynamic, we need to count the objects that are shown.
  byte AmountOfObjectsShown = 0;
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))], i)) AmountOfObjectsShown++;
    if (AmountOfObjectsShown - 1 == cursorY) bitSet(player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS)) + 1], i);

    // if an item is used decrease the item amount
    if (gameState == STATE_GAME_ITEMS)
    {
      if (bitRead(player.hasStuff[1], i))
      {
        player.itemsAmount[i] -= 1;
        if (player.itemsAmount[i] < 1) bitClear(player.hasStuff[0], i);
      }
    }
  }
}


#endif
