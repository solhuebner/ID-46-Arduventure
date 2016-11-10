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
  drawWord(93, 87, 2, WHITE, ALIGN_LEFT);
  if (!bitRead(player.equipedWeapon, cursorY))sprites.drawSelfMasked(87, 14 + (6*cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasWeapon, i))
    {
      drawWord(96 + i, 93, 14 + (6*countEquipment), WHITE, ALIGN_LEFT);
      if (bitRead(player.equipedWeapon, i)) sprites.drawSelfMasked(87, 14 + (6*countEquipment), font, 48);
      countEquipment++;
    }
  }
}

void drawArmor()
{
  byte countEquipment = 0;
  drawWord(94, 87, 2, WHITE, ALIGN_LEFT);
  if (!bitRead(player.equipedArmorType, cursorY))sprites.drawSelfMasked(87, 14 + (6*cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasArmorType, i))
    {
      drawWord(104 + i, 93, 14 + (6*countEquipment), WHITE, ALIGN_LEFT);
      if (bitRead(player.equipedArmorType, i)) sprites.drawSelfMasked(87, 14 + (6*countEquipment), font, 48);
      countEquipment++;
    }
  }
}

void drawAmulet()
{
  byte countEquipment = 0;
  drawWord(95, 87, 2, WHITE, ALIGN_LEFT);
  if (!bitRead(player.equipedAmulet, cursorY))sprites.drawSelfMasked(87, 14 + (6*cursorY), font, 44);
  for (byte i = 0; i < 8; i++)
  {
    if (bitRead (player.hasAmulet, i))
    {
      drawWord(112 + i, 93, 14 + (6*countEquipment), WHITE, ALIGN_LEFT);
      if (bitRead(player.equipedAmulet, i)) sprites.drawSelfMasked(87, 14 + (6*countEquipment), font, 48);
      countEquipment++;
    }
  }
}




#endif
