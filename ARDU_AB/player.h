#ifndef PLAYER_H
#define PLAYER_H

#include <Arduino.h>
#include "globals.h"

#define ITEMAMOUNT                   6

PROGMEM const unsigned char animSeq[] = { 0, 1, 2, 1 };

struct Player
{
  int x, y, health, healthTotal, magic, magicTotal, gold, experience, experienceForNextLevel;
  byte frame, currentMap, direction, level, attack, attackAddition, defense, defenseAddition, speed, speedAddition, weapon, armor, other;
  unsigned char name[6];
  byte items[ITEMAMOUNT];
  boolean tags;
  boolean walking;
};

Player player;

void setPlayer()
{
  player =
  {
    64, 24,                                 // position
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
    NONE,                                   // weapon
    NONE,                                   // armor
    NONE,                                   // other
    {5, 50, 50, 50, 50, 50},                // name
    {NONE, NONE, NONE, NONE, NONE, NONE},   // items
    true,
    false,
  };
}

void drawPlayer()
{
  if (arduboy.everyXFrames(6) && player.walking) player.frame = (++player.frame) % 4;
  sprites.drawPlusMask(player.x, player.y, player_plus_mask, pgm_read_byte(&animSeq[player.frame]) + 3 * player.direction);
}


#endif
