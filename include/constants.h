#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "clay/clay.h"

const Clay_Color PRIMARY_BACKGOUND   = {34, 40, 49, 255};
const Clay_Color SECONDARY_BACKGOUND = {49, 54, 63, 255};
const Clay_Color PRIMARY             = {238, 238, 238, 255};
const Clay_Color SECONDARY           = {118, 171, 174, 255};

enum FontID : uint8_t {
  FONT_ID_BODY_16  = 0,
  FONT_ID_BODY_24  = 1,
  FONT_ID_BODY_36  = 2,
  FONT_ID_TITLE_36 = 3,
  FONT_ID_TITLE_56 = 4,
};

#endif // !CONSTANTS_H
