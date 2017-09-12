  /*
  ARDUVENTURE DEMO, NOT THE FINISHED GAME !!!!!!

  Arduboy version 0.1:

  MADE by TEAM a.r.g. : http://www.team-arg.org/more-about.html

  2017 - JO3RI GANTOIS - GAVIN ATKIN - OLIVIER HUARD - SIEGFRIED CROES 

  Game License: MIT : https://opensource.org/licenses/MIT

  Story, characters, sprites, tiles, design and art: copyrighted to TEAM a.r.g.
*/


//determine the game
#define GAME_ID 46

#include "globals.h"
#include "menu.h"
#include "game.h"
#include "inputs.h"
#include "text.h"
#include "inventory.h"
#include "items.h"
#include "player.h"



typedef void (*FunctionPointer) ();

const FunctionPointer PROGMEM mainGameLoop[] = {
  stateMenuIntro,
  stateMenuMain,
  stateMenuContinue,
  stateMenuNew,
  stateMenuSound,
  stateGameNew,
  stateGamePlaying,
  stateGameInventory,
  stateGameEquip,
  stateGameStats,
  stateGameSave,
  stateGameEnd,
  showSubMenuStuff,
  showSubMenuStuff,
  showSubMenuStuff,
  showSubMenuStuff,
  
  stateGameOver,
};


void setup() {
  ATM.play(titleSong);
  arduboy.begin();
  arduboy.setFrameRate(60);                                 // set the frame rate of the game at 60 fps
}


void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.pollButtons();
  arduboy.clear();
  showPlayField();
  ((FunctionPointer) pgm_read_word (&mainGameLoop[gameState]))();
  if (question) drawQuestion();
  if (yesNo) drawYesNo();
  arduboy.display();
}

