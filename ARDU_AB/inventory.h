#ifndef INVENTORY_H
#define INVENTORY_H

#include <Arduino.h>
#include "globals.h"

void showInventory()
{
  drawSentence(4, 96, 2, WHITE, ALIGN_LEFT);
}

void drawItemsList()
{
  byte countEquipment = 0;
  sprites.drawErase(5, 9 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[0], i))
    {
      drawWord(97 + i, 12, 9 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}

void drawWeaponsList()
{
  byte countEquipment = 0;
  sprites.drawErase(5, 9 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[2], i))
    {
      drawWord(105 + i, 12, 9 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.hasStuff[3], i)) drawWord(81, 68, 9  + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}

void drawArmorList()
{
  byte countEquipment = 0;
  sprites.drawErase(5, 9 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[4], i))
    {
      drawWord(113 + i, 12, 9 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.hasStuff[5], i)) drawWord(81, 68, 9 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}

void drawAmuletList()
{
  byte countEquipment = 0;
  sprites.drawErase(5, 9 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[6], i))
    {
      drawWord(121 + i, 12, 9 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.hasStuff[7], i)) drawWord(81, 68, 9 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}

fillList(byte sortOfList)
{
  byte dynamicTextBoxSize = 0;
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasStuff[(2*(sortOfList - 2))], i))
    {
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = 97 + (8 * (sortOfList - 2)) + i;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = NEWLINE;
    }
  }
  dynamicTextbox[0] = dynamicTextBoxSize;
}


#endif
