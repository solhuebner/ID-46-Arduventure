#ifndef ITEMS_H
#define ITEMS_H

#include <Arduino.h>
#include "globals.h"
#include "text.h"

void selectItemsEquipment()
{
  // set the equipped flag or item used flag
  player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS))+1] = 0;
  bitSet(player.hasStuff[(2 * (gameState - STATE_GAME_ITEMS)) +1], cursorY);

  // if an item is used decrease the item amount
  if (gameState == STATE_GAME_ITEMS)
  {
    
  }
}


#endif
