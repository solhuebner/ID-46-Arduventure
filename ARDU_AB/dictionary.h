#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <Arduino.h>
#include "globals.h"

#define SPACE                         0
#define NEWLINE                       254
#define END                           255
#define ALIGN_LEFT                    0
#define ALIGN_RIGHT                   1


PROGMEM const unsigned char library[] =
{
  // PLACE  0 : empty
  SPACE, END,
  // PLACE  1 : CONTINUE
  3, 15, 14, 20, 9, 14, 21, 5, END,
  // PLACE  2 : NEW
  14, 5, 23, END,
  // PLACE  3 : GAME
  7, 1, 13, 5, END,
  // PLACE  4 : SND
  19, 14, 4, END,
  // PLACE  5 : OFF
  15, 6, 6, END,
  // PLACE  6 : ON
  15, 14, END,
  // PLACE  7 : YOUR
  25, 15, 21, 18, END,
  // PLACE  8 : NAME
  14, 1, 13, 5, END,
  // PLACE  9 : END
  5, 14, 4, END,
  // PLACE 10 : WELCOME
  23, 5, 12, 3, 15, 13, 5, END,
  // PLACE 11 : TO
  20, 15, END,
  // PLACE 12 : ARDUVILLAGE
  1, 18, 4, 21, 22, 9, 12, 12, 1, 7, 5, END,
  // PLACE 13 : I
  9, END,
  // PLACE 14 : WISH
  23, 9, 19, 8, END,
  // PLACE 15 : HAD
  8, 1, 4, END,
  // PLACE 16 : A
  1, END,
  // PLACE 17 : FISHING
  6, 9, 19, 8, 9, 14, 7, END,
  // PLACE 18 : ROD
  18, 15, 4, END,
  // PLACE 19 : WHAT
  23, 8, 1, 20, END,
  // PLACE 20 : DO
  4, 15, END,
  // PLACE 21 : YOU
  25, 15, 21, END,
  // PLACE 22 : BUY
  2, 21, 25, END,
  // PLACE 23 : WOULD
  23, 15, 21, 12, 4, END,
  // PLACE 24 : LIKE
  12, 9, 11, 5, END,
  // PLACE 25 : TO
  20, 15, END,
  // PLACE 26 : SELL
  19, 5, 12, 12, END,

 
  // PLACE 27 : CHARACTER 0
  27, END,
  // PLACE 28 : CHARACTER 1
  28, END,
  // PLACE 29 : CHARACTER 2
  29, END,
  // PLACE 30 : CHARACTER 3
  30, END,
  // PLACE 31 : CHARACTER 4
  31, END,
  // PLACE 32 : CHARACTER 5
  32, END,
  // PLACE 33 : CHARACTER 6
  33, END,
  // PLACE 34 : CHARACTER 7
  34, END,
  // PLACE 35 : CHARACTER 8
  35, END,
  // PLACE 36 : CHARACTER 9
  36, END,
  // PLACE 37 : CHARACTER .
  37, END,
  // PLACE 38 : CHARACTER ,
  38, END,
  // PLACE 39 : CHARACTER !
  39, END,
  // PLACE 40 : CHARACTER ?
  40, END,
  // PLACE 41 : CHARACTER '
  41, END,
  // PLACE 42 : CHARACTER :
  42, END,
  // PLACE 43 : CHARACTER /
  43, END,
  // PLACE 44 : arrow right
  44, END,
  // PLACE 45 : arrow left
  45, END,
  // PLACE 46 : arrow up
  46, END,
  // PLACE 47 : arrow down
  47, END,
  // place 48 : diamond
  48, END,
  // place 49 : €
  49, END,
  // place 50 : _           
  50, END,
  // place 51 : *
  51, END,
  // place 52 : (
  52, END,
  // place 53 : )
  53, END,
  // place 54 : +
  54, END,
  // place 55 : -
  55, END,
  // place 56 : full
  56, END,
  
  // PLACE 57 : CAN
  3, 1, 14, END,
  // PLACE 58 : NOT
  5, 14, 4, END,
  // PLACE 59 : ESCAPE
  5, 19, 3, 1, 16, 5, END,
  // PLACE 60 : GOT
  7, 15, 20, END,
  // PLACE 61 : AWAY
  1, 23, 1, 25, END,
  // PLACE 62 : SAFELY
  19, 1, 6, 5, 12, 25, END,
  // PLACE 63 : YOU
  25, 15, 21, END,
  // PLACE 64 : WIN
  23, 9, 14, END,
  // PLACE 65 : SLEEP
  19, 12, 5, 5, 16, END,
  // PLACE 66 : RESTORE
  18, 5, 19, 20, 15, 18, 5, END,
  // PLACE 67 : ALL
  1, 12, 12, END,
  // PLACE 68 : HEALTH
  8, 5, 1, 12, 20, 8, END,
  // PLACE 69 : SAVE
  19, 1, 22, 5, END,
  // PLACE 70 : PROGRESS
  16, 18, 15, 7, 18, 5, 19, 19, END,
  // PLACE 71 : USE
  21, 19, 5, END,
  // PLACE 72 : EQUIP
  5, 17, 21, 9, 16, END,
  // PLACE 73 : UN
  21, 14, END,
  // PLACE 74 : LEVEL
  12, 5, 22, 5, 12, END,
  // PLACE 75 : UP
  21, 16, END,
  // PLACE 76 : THE
  20, 8, 5, END,
  // PLACE 77 : BRIDGE
  2, 18, 9, 4, 7, 5, END,
  // PLACE 78 : IS
  9, 19, END,
  // PLACE 79 : BROKEN
  2, 18, 15 , 11, 5, 14, END,
  // PLACE 80 : ENDLESS
  5, 14, 4, 12, 5, 19, 19, END,
  // PLACE 81 : WOODS
  23, 15, 15, 4, 19, END,
  // PLACE 82 : AHEAD
  1, 8, 5, 1, 4, END,
  // PLACE 83 : ITEMS
  9, 20, 5, 13, 19, END,
  // PLACE 84 : STATS
  19, 20, 1, 20, 19, END,
};

PROGMEM const unsigned char sentences[] =
{
  // 0 : CONTINUE NEW GAME
  2, SPACE, 3, END,
  // 1 : SND  OFF
  4, SPACE, SPACE, 5, END,
  // 2 : SND   ON
  4, SPACE, SPACE, SPACE, 6, END,
  // 3 : WHAT IS YOUR NAME
  7, SPACE, 8, END,
  // 4 : ITEMS STATS SAVE
  83, NEWLINE, NEWLINE, 84, NEWLINE, NEWLINE, 69, END,
};


#endif
