#ifndef INVENTORY_H
#define INVENTORY_H

#include <Arduino.h>
#include "globals.h"

void showInventory()
{
  drawSentence(4, 96, 2, WHITE, ALIGN_LEFT);
}

void drawWeapons()
{
  //if (drawWord(byte wordOfLibrary, byte x, byte y, boolean color, boolean alignment)
}

#endif
