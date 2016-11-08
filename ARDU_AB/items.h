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
  Serial.println (cursorY);
  byte dynamicTextBoxSize = 0;
  switch (cursorY)
  {
    case 0:
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = 96;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = NEWLINE;
    case 1:
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = 97;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = NEWLINE;
    case 2:
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = 98;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = SPACE;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = 99;
      dynamicTextBoxSize++;
      dynamicTextbox[dynamicTextBoxSize] = NEWLINE;
  }
  dynamicTextbox[0] = dynamicTextBoxSize;
}


#endif
