#ifndef ITEMS_H
#define ITEMS_H

#include <Arduino.h>
#include "globals.h"
#include "text.h"

void selectItemsEquipment()
{
  // set the equipped flag or item used flag
  player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS)) + 1] = 0;
  byte k = 0;
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))], i)) k++;
    if (k-1 == cursorY) bitSet(player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS)) + 1], i);
  }
  

  // if an item is used decrease the item amount
  if (gameState == STATE_GAME_ITEMS)
  {
    for (byte i = 0; i < 8; i++)
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
