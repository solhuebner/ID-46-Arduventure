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
  if (!bitRead(player.equipedWeapon, cursorY))sprites.drawErase(1, 14 + (6*cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasWeapon, i))
    {
      drawWord(97 + i, 8, 14 + (6*countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.equipedWeapon, i)) sprites.drawErase(2, 14 + (6*countEquipment), font, 48);
      countEquipment++;
    }
  }
}

void drawArmor()
{
  byte countEquipment = 0;
  if (!bitRead(player.equipedArmorType, cursorY))sprites.drawErase(1, 14 + (6*cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasArmorType, i))
    {
      drawWord(105 + i, 8, 14 + (6*countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.equipedArmorType, i)) sprites.drawErase(2, 14 + (6*countEquipment), font, 48);
      countEquipment++;
    }
  }
}

void drawAmulet()
{
  byte countEquipment = 0;
  if (!bitRead(player.equipedAmulet, cursorY))sprites.drawErase(1, 14 + (6*cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasAmulet, i))
    {
      drawWord(113 + i, 8, 14 + (6*countEquipment), BLACK, ALIGN_LEFT);
      if (bitRead(player.equipedAmulet, i)) sprites.drawErase(2, 14 + (6*countEquipment), font, 48);
      countEquipment++;
    }
  }
}




#endif
