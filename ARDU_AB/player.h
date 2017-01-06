#ifndef PLAYER_H
#define PLAYER_H

#include <Arduino.h>
#include "globals.h"
#include "text.h"

#define ITEMAMOUNT                   6

PROGMEM const unsigned char animSeq[] = { 0, 1, 2, 1 };

struct Player
{
  int x, y, health, healthTotal, magic, magicTotal, gold, experience, experienceForNextLevel;
  byte frame, currentMap, direction, level, attack, attackAddition, defense, defenseAddition, speed, speedAddition;
  unsigned char hasStuff[8];
  unsigned char itemsAmount[8];
  unsigned char name[6];
  boolean tags;
  boolean walking;
};

Player player;

void setPlayer()
{
  player =
  {
    224, 640,                               // position
    20, 20,                                 // health
    0, 10,                                  // magic
    100,                                    // gold
    0, 50,                                  // experience
    0,                                      // frame
    0,                                      // currentMap
    FACING_SOUTH,                           // direction
    1,                                      // level
    5, 0,                                   // attack
    5, 0,                                   // defence
    5, 0,                                   // speed

    {
      0B11111111,                             // hasItem
      0B00000000,                             // using the item
      //|||||||└-------------------------------> 0 apple
      //||||||└--------------------------------> 1 cider
      //|||||└---------------------------------> 2 anise
      //||||└----------------------------------> 3 absinthe
      //|||└-----------------------------------> 4 ruby
      //||└------------------------------------> 5 sapphire
      //|└-------------------------------------> 6 emerald
      //└--------------------------------------> 7 diamond

      0B11111111,                             // hasWeapon
      0B00001000,                             // equipedWaepon
      //|||||||└-------------------------------> 0 sling
      //||||||└--------------------------------> 1 knife
      //|||||└---------------------------------> 2 rapier
      //||||└----------------------------------> 3 sword
      //|||└-----------------------------------> 4 axe
      //||└------------------------------------> 5 lance
      //|└-------------------------------------> 6 spear
      //└--------------------------------------> 7 bow

      0B11111111,                             // hasArmorType
      0B00000001,                             // equipedArmorType
      //|||||||└-------------------------------> 0 wool
      //||||||└--------------------------------> 1 linen
      //|||||└---------------------------------> 2 leathr
      //||||└----------------------------------> 3 bone
      //|||└-----------------------------------> 4 copper
      //||└------------------------------------> 5 bronze
      //|└-------------------------------------> 6 iron
      //└--------------------------------------> 7 steel

      0B11111111,                             // hasAmulet
      0B00000010,                             // equipedAmulet
      //|||||||└-------------------------------> 0 health
      //||||||└--------------------------------> 1 magic
      //|||||└---------------------------------> 2 speed
      //||||└----------------------------------> 3 luck
      //|||└-----------------------------------> 4 gold
      //||└------------------------------------> 5 cloak
      //|└-------------------------------------> 6 escape
      //└--------------------------------------> 7 ruby
    },

    {1, 5, 3, 4, 7, 6, 9, 46},             // amount of each item (max 64)

    {5, 50, 50, 50, 50, 50},                    // name
    true,                                       // tags
    false,                                      // walking
  };
}

void drawPlayer()
{
  if (arduboy.everyXFrames(6) && player.walking) player.frame = (++player.frame) % 4;
  sprites.drawPlusMask(player.x - cam.x, player.y - cam.y, player_plus_mask, pgm_read_byte(&animSeq[player.frame]) + 3 * player.direction);
}

void drawPlayerStats()
{
  byte xOffset;
  drawSentence(8, 6, 2, WHITE, ALIGN_LEFT);
  drawWordRam(player.name, 60, 2, WHITE, ALIGN_LEFT);
  drawRectangle(0, 10, 130, 64, WHITE);
  drawSentence(6, 6, 14, BLACK, ALIGN_LEFT);
  drawSentence(7, 90, 14, BLACK, ALIGN_LEFT);
  drawNumbersRam(player.gold, 42 , 14, BLACK, ALIGN_LEFT);

  drawNumbersRam(player.health, 36, 26, BLACK, ALIGN_LEFT);
  xOffset = 6 * countDigitsInInt(player.health);
  drawWord(43, 36 + xOffset, 26, BLACK, ALIGN_LEFT);
  drawNumbersRam(player.healthTotal, 42 + xOffset, 26, BLACK, ALIGN_LEFT);

  drawNumbersRam(player.magic, 36, 38, BLACK, ALIGN_LEFT);
  xOffset = 6 * countDigitsInInt(player.magic);
  drawWord(43, 36 + xOffset, 38, BLACK, ALIGN_LEFT);
  drawNumbersRam(player.magicTotal, 42 + xOffset, 38, BLACK, ALIGN_LEFT);

  drawNumbersRam(player.experience, 84, 56, BLACK, ALIGN_LEFT);
  xOffset = 6 * countDigitsInInt(player.experience);
  drawWord(43, 84 + xOffset, 56, BLACK, ALIGN_LEFT);
  drawNumbersRam(player.experienceForNextLevel, 90 + xOffset, 56, BLACK, ALIGN_LEFT);

  drawNumbersRam(player.level, 126 , 14, BLACK, ALIGN_RIGHT);
  drawNumbersRam(player.attack, 126 , 26, BLACK, ALIGN_RIGHT);
  drawNumbersRam(player.defense, 126 , 32, BLACK, ALIGN_RIGHT);
  drawNumbersRam(player.speed, 126 , 38, BLACK, ALIGN_RIGHT);
}


#endif
