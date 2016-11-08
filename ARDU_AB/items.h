#ifndef ITEMS_H
#define ITEMS_H

#include <Arduino.h>
#include "globals.h"
#include "text.h"

#define ITEM_APPLE 0
#define ITEM_POTION 1
#define ITEM_HEALSTONE 2
#define ITEM_DAGGER 3
#define ITEM_SHORTSWORD 4
#define ITEM_IRONARMOR 5

void getItems()
{
  byte dynamicTextBoxSize = 0;
  switch (cursorY)
  {
    case 0:
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = 96;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = NEWLINE;
    case 1:
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = 97;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = NEWLINE;
    case 2:
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = 98;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = SPACE;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = 99;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize - cursorY] = NEWLINE;
  }
  dynamicTextbox[0] = dynamicTextBoxSize;
}


#endif
