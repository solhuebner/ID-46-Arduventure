#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <Arduino.h>
#include "globals.h"

unsigned char dynamicTextbox[44];

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
  // PLACE 59 : ESCAPE
  6,
  5, 19, 3, 1, 16, 5,
  // PLACE 60 : GOT
  3,
  7, 15, 20,
  // PLACE 61 : AWAY
  4,
  1, 23, 1, 25,
  // PLACE 62 : SAFELY
  6,
  19, 1, 6, 5, 12, 25,
  // PLACE 63 : YOU
  3,
  25, 15, 21,
  // PLACE 64 : WIN
  3,
  23, 9, 14,
  // PLACE 65 : SLEEP
  5,
  19, 12, 5, 5, 16,
  // PLACE 66 : RESTORE
  7,
  18, 5, 19, 20, 15, 18, 5,
  // PLACE 67 : ALL
  3,
  1, 12, 12,
  // PLACE 68 : HEALTH
  6,
  8, 5, 1, 12, 20, 8,
  // PLACE 69 : SAVE
  4,
  19, 1, 22, 5,
  // PLACE 70 : PROGRESS
  8,
  16, 18, 15, 7, 18, 5, 19, 19,
  // PLACE 71 : USE
  3,
  21, 19, 5,
  // PLACE 72 : EQUIP
  5,
  5, 17, 21, 9, 16,
  // PLACE 73 : UN
  2,
  21, 14,
  // PLACE 74 : LEVEL
  5,
  12, 5, 22, 5, 12,
  // PLACE 75 : UP
  2,
  21, 16,
  // PLACE 76 : THE
  3,
  20, 8, 5,
  // PLACE 77 : BRIDGE
  6,
  2, 18, 9, 4, 7, 5,
  // PLACE 78 : IS
  2,
  9, 19,
  // PLACE 79 : BROKEN
  6,
  2, 18, 15 , 11, 5, 14,
  // PLACE 80 : ENDLESS
  7,
  5, 14, 4, 12, 5, 19, 19,
  // PLACE 81 : WOODS
  5,
  23, 15, 15, 4, 19,
  // PLACE 82 : AHEAD
  5,
  1, 8, 5, 1, 4,
  // PLACE 83 : ITEMS
  5,
  9, 20, 5, 13, 19,
  // PLACE 84 : STATS
  5,
  19, 20, 1, 20, 19,
  // PLACE 85 : GOLD
  4,
  7, 15, 12, 4,
  // PLACE 86 : HP
  2,
  8, 16,
  // PLACE 87 : MP
  2,
  13, 16,
  // PLACE 88 : EXP
  3,
  5, 24, 16,
  // PLACE 89 : LV
  2,
  12, 22,
  // PALCE 90 : ATK
  3,
  1, 20, 11,
  // PLACE 91 : DEF
  3,
  4, 5, 6,
  // PLACE 92 : SPD
  3,
  19, 16, 4,
  // PLACE 93 : YES
  3,
  25, 5, 19,
  // PLACE 94 : NO
  2,
  14, 15,
  // PLACE 95 : OF
  2,
  15, 6,
  // PLACE 96 : WEAPON
  6,
  23, 5, 1, 16, 15, 14,
  // PLACE 97 : ARMOR
  5,
  1, 18, 13, 15, 18,
  // PLACE 98 : EXTRA
  5,
  5, 24, 20, 18, 1,
  // PLACE 99 : APPLE
  5,
  1, 16, 16, 12, 5,
  // PLACE 100 : POTION
  6,
  16, 15, 20, 9, 15, 14,
  // PLACE 101 : HEALING
  7,
  8, 5, 1, 12, 9, 14, 7,
  // PLACE 102 : STONE
  5,
  19, 20, 15, 14, 5,
  // PLACE 103 : KNIFE
  5,
  11, 14, 9, 6, 5,
  // PLACE 104 : DAGGER
  6,
  4, 1, 7, 7, 5, 18,
  // PLACE 105 : SWORD
  5,
  19, 23, 15, 18, 4,
  // PLACE 106 : WOODEN
  6,
  23, 15, 15, 4, 5, 14,
  // PLACE 107 : BRONZE
  6,
  2, 18, 15, 14, 26, 5,
  // PLACE 108 : IRON
  4,
  9, 18, 15, 14,

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
  // PLACE  3 : WHAT IS YOUR NAME
  3,
  7, SPACE, 8,
  // PLACE  4 : ITEMS EQUIP STATS SAVE END
  13,
  83, NEWLINE, NEWLINE, 72, NEWLINE, NEWLINE, 84, NEWLINE, NEWLINE, 69, NEWLINE, NEWLINE, 9,
  // PLACE  5 : SAVE PROGRESS ?
  5,
  69, SPACE, 70, SPACE, 40,
  // PLACE  6 : GOLD: € MV: HP: EXP TO LEVEL UP:
  26,
  85, 42, 49, NEWLINE, NEWLINE, 86, SPACE, SPACE, 42, NEWLINE, NEWLINE, 87, SPACE, SPACE, 42, NEWLINE, NEWLINE, NEWLINE, 87, SPACE, 11, SPACE, 89, SPACE, 75, 42,
  // PLACE  7 : LV: ATK: DEF: SPD:
  13,
  89, SPACE, 42, NEWLINE, NEWLINE, 90, 42, NEWLINE, 91, 42, NEWLINE, 92, 42,
  // PLACE  8 : STATS OF
  3,
  84, SPACE, 95,
  // PLACE  9 : YES NO
  3,
  93, NEWLINE, 94,
  // PLACE 10 : WEAPON ARMOR EXTRA
  7,
  96, NEWLINE, NEWLINE, 97, NEWLINE, NEWLINE, 98,

};


#endif
