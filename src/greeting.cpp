#include "greeting.h"

#include "constants.h"

void Greeting(Clay_Sizing layoutExpand) {
  CLAY(
    CLAY_ID("Greeting"),
    CLAY_LAYOUT({
      .sizing =
        {.width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_FIXED(720 - 60)},
      .childAlignment =
        {
                 .x = CLAY_ALIGN_X_CENTER,
                 .y = CLAY_ALIGN_Y_CENTER,
                 },
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
  }),
    CLAY_RECTANGLE({.color = {0}})
  ) {
    /* Hi */
    CLAY_TEXT(
      CLAY_STRING("Hi!"),
      CLAY_TEXT_CONFIG({
        .textColor = SECONDARY,
        .fontId    = FONT_ID_BODY_24,
        .fontSize  = 48,
      })
    );

    /* Hi */
    CLAY_TEXT(
      CLAY_STRING("I am Anshu Gahire"),
      CLAY_TEXT_CONFIG({
        .textColor = PRIMARY,
        .fontId    = FONT_ID_BODY_24,
        .fontSize  = 48,
      })
    );

    /* aka FosRex */
    CLAY_TEXT(
      CLAY_STRING("aka FosRex"),
      CLAY_TEXT_CONFIG({
        .textColor = SECONDARY,
        .fontId    = FONT_ID_BODY_24,
        .fontSize  = 48,
      })
    );

    /* Chevron Down */
  };
}
