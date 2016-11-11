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
  byte countEquipment = 0;
  sprites.drawErase(1, 13 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasWeapon, i))
    {
      drawWord(97 + i, 8, 13 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.equipedWeapon, i)) drawWord(81, 68, 13 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}

void drawArmor()
{
  byte countEquipment = 0;
  sprites.drawErase(1, 13 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasArmorType, i))
    {
      drawWord(105 + i, 8, 13 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.equipedArmorType, i)) drawWord(81, 68, 13 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}

void drawAmulet()
{
  byte countEquipment = 0;
  sprites.drawErase(1, 13 + (6 * cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasAmulet, i))
    {
      drawWord(113 + i, 8, 13 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.equipedAmulet, i)) drawWord(81, 68, 13 + (6 * countEquipment), BLACK, ALIGN_LEFT);
      countEquipment++;
    }
  }
}




#endif
