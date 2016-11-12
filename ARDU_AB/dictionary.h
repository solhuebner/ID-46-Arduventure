#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <Arduino.h>
#include "globals.h"

unsigned char dynamicTextbox[65];

PROGMEM const unsigned char library[] =
{
  // PLACE  0 : empty
  1,
  SPACE,
  // PLACE  1 : CONTINUE
  8,
  3, 15, 14, 20, 9, 14, 21, 5,
  // PLACE  2 : NEW
  3,
  14, 5, 23,
  // PLACE  3 : GAME
  4,
  7, 1, 13, 5,
  // PLACE  4 : SND
  3,
  19, 14, 4,
  // PLACE  5 : OFF
  3,
  15, 6, 6,
  // PLACE  6 : ON
  2,
  15, 14,
  // PLACE  7 : YOUR
  4,
  25, 15, 21, 18,
  // PLACE  8 : NAME
  4,
  14, 1, 13, 5,
  // PLACE  9 : END
  3,
  5, 14, 4,
  // PLACE 10 : WELCOME
  7,
  23, 5, 12, 3, 15, 13, 5,
  // PLACE 11 : TO
  2,
  20, 15,
  // PLACE 12 : ARDUVILLAGE
  11,
  1, 18, 4, 21, 22, 9, 12, 12, 1, 7, 5,
  // PLACE 13 : I
  1,
  9,
  // PLACE 14 : WISH
  4,
  23, 9, 19, 8,
  // PLACE 15 : HAD
  3,
  8, 1, 4,
  // PLACE 16 : A
  1,
  1,
  // PLACE 17 : FISHING
  7,
  6, 9, 19, 8, 9, 14, 7,
  // PLACE 18 : ROD
  3,
  18, 15, 4,
  // PLACE 19 : WHAT
  4,
  23, 8, 1, 20,
  // PLACE 20 : DO
  2,
  4, 15,
  // PLACE 21 : YOU
  3,
  25, 15, 21,
  // PLACE 22 : BUY
  3,
  2, 21, 25,
  // PLACE 23 : WOULD
  5,
  23, 15, 21, 12, 4,
  // PLACE 24 : LIKE
  4,
  12, 9, 11, 5,
  // PLACE 25 : TO
  2,
  20, 15,
  // PLACE 26 : SELL
  4,
  19, 5, 12, 12,


  // PLACE 27 : CHARACTER 0
  1,
  27,
  // PLACE 28 : CHARACTER 1
  1,
  28,
  // PLACE 29 : CHARACTER 2
  1,
  29,
  // PLACE 30 : CHARACTER 3
  1,
  30,
  // PLACE 31 : CHARACTER 4
  1,
  31,
  // PLACE 32 : CHARACTER 5
  1,
  32,
  // PLACE 33 : CHARACTER 6
  1,
  33,
  // PLACE 34 : CHARACTER 7
  1,
  34,
  // PLACE 35 : CHARACTER 8
  1,
  35,
  // PLACE 36 : CHARACTER 9
  1,
  36,
  // PLACE 37 : CHARACTER .
  1,
  37,
  // PLACE 38 : CHARACTER ,
  1,
  38,
  // PLACE 39 : CHARACTER !
  1,
  39,
  // PLACE 40 : CHARACTER ?
  1,
  40,
  // PLACE 41 : CHARACTER '
  1,
  41,
  // PLACE 42 : CHARACTER :
  1,
  42,
  // PLACE 43 : CHARACTER /
  1,
  43,
  // PLACE 44 : arrow right
  1,
  44,
  // PLACE 45 : arrow left
  1,
  45,
  // PLACE 46 : arrow up
  1,
  46,
  // PLACE 47 : arrow down
  1,
  47,
  // place 48 : diamond
  1,
  48,
  // place 49 : €
  1,
  49,
  // place 50 : _
  1,
  50,
  // place 51 : *
  1,
  51,
  // place 52 : (
  1,
  52,
  // place 53 : )
  1,
  53,
  // place 54 : +
  1,
  54,
  // place 55 : -
  1,
  55,
  // place 56 : full
  1,
  56,


  // PLACE 57 : CAN
  3,
  3, 1, 14,
  // PLACE 58 : NOT
  3,
  14, 15, 20,
  // PLACE 59 : GOT
  3,
  7, 15, 20,
  // PLACE 60 : AWAY
  4,
  1, 23, 1, 25,
  // PLACE 61 : SAFELY
  6,
  19, 1, 6, 5, 12, 25,
  // PLACE 62 : YOU
  3,
  25, 15, 21,
  // PLACE 63 : WIN
  3,
  23, 9, 14,
  // PLACE 64 : SLEEP
  5,
  19, 12, 5, 5, 16,
  // PLACE 65 : RESTORE
  7,
  18, 5, 19, 20, 15, 18, 5,
  // PLACE 66 : ALL
  3,
  1, 12, 12,
  // PLACE 67 : SAVE
  4,
  19, 1, 22, 5,
  // PLACE 68 : PROGRESS
  8,
  16, 18, 15, 7, 18, 5, 19, 19,
  // PLACE 69 : USE
  3,
  21, 19, 5,
  // PLACE 70 : EQUIP
  5,
  5, 17, 21, 9, 16,
  // PLACE 71 : UNEQUIP
  7,
  21, 14, 5, 17, 21, 9, 16,
  // PLACE 72 : LEVEL
  5,
  12, 5, 22, 5, 12,
  // PLACE 73 : UP
  2,
  21, 16,
  // PLACE 74 : THE
  3,
  20, 8, 5,
  // PLACE 75 : BRIDGE
  6,
  2, 18, 9, 4, 7, 5,
  // PLACE 76 : IS
  2,
  9, 19,
  // PLACE 77 : BROKEN
  6,
  2, 18, 15 , 11, 5, 14,
  // PLACE 78 : LESS
  4,
  12, 5, 19, 19,
  // PLACE 79 : WOODS
  5,
  23, 15, 15, 4, 19,
  // PLACE 80 : AHEAD
  5,
  1, 8, 5, 1, 4,
  // PLACE 81 : EQUIPPED
  8,
  5, 17, 21, 9, 16, 16, 5, 4,
  // PLACE 82 : STATS
  5,
  19, 20, 1, 20, 19,
  // PLACE 83 : HP
  2,
  8, 16,
  // PLACE 84 : MP
  2,
  13, 16,
  // PLACE 85 : EXP
  3,
  5, 24, 16,
  // PLACE 86 : LV
  2,
  12, 22,
  // PALCE 87 : ATK
  3,
  1, 20, 11,
  // PLACE 88 : DEF
  3,
  4, 5, 6,
  // PLACE 89 : SPD
  3,
  19, 16, 4,
  // PLACE 90 : YES
  3,
  25, 5, 19,
  // PLACE 91 : NO
  2,
  14, 15,
  // PLACE 92 : OF
  2,
  15, 6,


  // PLACE 93 : ITEMS
  5,
  9, 20, 5, 13, 19,
  // PLACE 94 : WEAPON
  6,
  23, 5, 1, 16, 15, 14,
  // PLACE 95 : ARMOR
  5,
  1, 18, 13, 15, 18,
  // PLACE 96 : AMULET
  6,
  1, 13, 21, 12, 5, 20,


  // PLACE 97 : APPLE
  5,
  1, 16, 16, 12, 5,
  // PLACE 98 : CIDER
  5,
  3, 9, 4, 5, 18,
  // PLACE 99 : ANISE
  5,
  1, 14, 9, 19, 5,
  // PLACE 100 : ABSINTHE
  8,
  1, 2, 19, 9, 14, 20, 8, 5,
  // PLACE 101 : RUBY
  4,
  18, 21, 2, 25,
  // PLACE 102 : SAPPHIRE
  8,
  19, 1, 16, 16, 8, 9, 18, 5,
  // PLACE 103 : EMERALD
  7,
  5, 13, 5, 18, 1, 12, 4,
  // PLACE 104 : DIAMOND
  7,
  4, 9, 1, 13, 15, 14, 4,
  // PLACE 105 : SLING
  5,
  19, 12, 9, 14, 7,
  // PLACE 106 : KNIFE
  5,
  11, 14, 9, 6, 5,
  // PLACE 107 : RAPIER
  6,
  18, 1, 16, 9, 5, 18,
  // PLACE 108 : SWORD
  5,
  19, 23, 15, 18, 4,
  // PLACE 109 : AXE
  3,
  1, 24, 5,
  // PLACE 110 : LANCE
  5,
  12, 1, 14, 3, 5,
  // PLACE 111 : SPEAR
  5,
  19, 16, 5, 1, 18,
  // PLACE 112 : BOW
  3,
  2, 15, 23,
  // PLACE 113 : WOOL
  4,
  23, 15, 15, 12,
  // PLACE 114 : LINEN
  5,
  12, 9, 14, 5, 14,
  // PLACE 115 : LEATHER
  7,
  12, 5, 1, 20, 8, 5, 18,
  // PLACE 116 : BONE
  4,
  2, 15, 14, 5,
  // PLACE 117 : COPPER
  6,
  3, 15, 16, 16, 5, 18,
  // PLACE 118 : BRONZE
  6,
  2, 18, 15, 14, 26, 5,
  // PLACE 119 : IRON
  4,
  9, 18, 15, 14,
  // PLACE 120 : STEEL
  5,
  19, 20, 5, 5, 12,
  // PLACE 121 : HEALTH
  6,
  8, 5, 1, 12, 20, 8,
  // PLACE 122 : MAGIC
  5,
  13, 1, 7, 9, 3,
  // PLACE 123 : SPEED
  5,
  19, 16, 5, 5, 4,
  // PLACE 124 : LUCK
  4,
  12, 21, 3, 11,
  // PLACE 125 : GOLD
  4,
  7, 15, 12, 4,
  // PLACE 126 : CLOAK
  5,
  3, 12, 15, 1, 11,
  // PLACE 127 : ESCAPE
  6,
  5, 19, 3, 1, 16, 5,
  // PLACE 128 : RUBY
  4,
  18, 21, 2, 25,




};


PROGMEM const unsigned char sentences[] =
{
  // PLACE 0 : NEW GAME
  3,
  2, SPACE, 3,
  // PLACE 1 : SND  OFF
  4,
  4, SPACE, SPACE, 5,
  // PLACE  2 : SND   ON
  5,
  4, SPACE, SPACE, SPACE, 6,
  // PLACE  3 : YOUR NAME ?
  5,
  7, SPACE, 8, SPACE, 40,

  // PLACE  4 : ITEMS EQUIP STATS SAVE END
  13,
  93, NEWLINE, NEWLINE, 70, NEWLINE, NEWLINE, 82, NEWLINE, NEWLINE, 67, NEWLINE, NEWLINE, 9,

  // PLACE  5 : SAVE PROGRESS ?
  5,
  69, SPACE, 70, SPACE, 40,
  // PLACE  6 : GOLD: € MP: HP: EXP TO LV UP:
  26,
  116, 42, 49, NEWLINE, NEWLINE, 84, SPACE, SPACE, 42, NEWLINE, NEWLINE, 83, SPACE, SPACE, 42, NEWLINE, NEWLINE, NEWLINE, 85, SPACE, 11, SPACE, 86, SPACE, 73, 42,
  // PLACE  7 : LV: ATK: DEF: SPD:
  13,
  86, SPACE, 42, NEWLINE, NEWLINE, 87, 42, NEWLINE, 88, 42, NEWLINE, 89, 42,
  // PLACE  8 : STATS OF
  3,
  82, SPACE, 92,
  // PLACE  9 : YES NO
  3,
  90, NEWLINE, 91,
  // PLACE 10 : WEAPON ARMOR AMULET
  7,
  94, NEWLINE, NEWLINE, 95, NEWLINE, NEWLINE, 96,

};


#endif
