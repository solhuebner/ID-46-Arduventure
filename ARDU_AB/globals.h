#ifndef GLOBALS_H
#define GLOBALS_H

#include <Arduino.h>
#include "Arglib.h"
#include "bitmaps.h"


//define menu states (on main menu)
#define STATE_MENU_INTRO              0
#define STATE_MENU_MAIN               1
#define STATE_MENU_CONTINUE           2
#define STATE_MENU_NEW                3
#define STATE_MENU_SOUND              4

//define game states (on main menu)
#define STATE_GAME_NEW                5
#define STATE_GAME_PLAYING            6
#define STATE_GAME_INVENTORY          7
#define STATE_GAME_ITEMS              8
#define STATE_GAME_EQUIP              9
#define STATE_GAME_STATS              10
#define STATE_GAME_SAVE               11
#define STATE_GAME_END                12
#define STATE_GAME_WEAPON             13
#define STATE_GAME_ARMOR              14
#define STATE_GAME_AMULET             15
#define STATE_GAME_OVER               16

#define GAME_TOP                      0
#define GAME_BOTTOM                   48
#define GAME_LEFT                     0
#define GAME_RIGHT                    112

#define FACING_SOUTH                  0
#define FACING_WEST                   1
#define FACING_NORTH                  2
#define FACING_EAST                   3

#define SPACE                         0
#define NEWLINE                       254
#define NONE                          255
#define ALIGN_LEFT                    0
#define ALIGN_RIGHT                   1

Arduboy arduboy;
Sprites sprites(arduboy);

//byte gameState = STATE_MENU_INTRO;           // start the game with the TEAM a.r.g. logo
byte gameState = STATE_MENU_MAIN;
byte gameStatePrevious = gameState;
byte menuSelection = STATE_MENU_CONTINUE;      // PLAY menu item is pre-selected
byte globalCounter = 0;
byte currentLetter = 0;
byte cursorX = 0;
byte cursorY = 0;


void drawRectangle(byte startX, byte startY, byte endX, byte endY, byte color )
{
  byte rectangleX = startX;
  while (startY < endY)
  {
    if (!color)sprites.drawErase(rectangleX, startY, font, 56);
    else sprites.drawSelfMasked(rectangleX, startY, font, 56);
    rectangleX += 5;
    if (rectangleX > endX - 5)
    {
      startY += 8;
      rectangleX = startX;
    }
  }
}

void saveGame()
{

}


#endif
