#include "navigation_bar.h"

#include "clay/clay.h"
#include "constants.h"

void RenderNavBarButton(Clay_String text) {
  CLAY(
    CLAY_LAYOUT({
      .padding = {16, 16}
  }),
    CLAY_RECTANGLE({.color = SECONDARY_BACKGOUND})
  ) {
    CLAY_TEXT(
      text,
      CLAY_TEXT_CONFIG({
        .textColor = SECONDARY,
        .fontId    = FONT_ID_BODY_16,
        .fontSize  = 26,
      })
    );
  }
}

void NavigationBar() {
  /* Navigation Bar */
  CLAY(
    CLAY_ID("NavBar"),
    CLAY_RECTANGLE({
      .color = SECONDARY_BACKGOUND,
  }),
    CLAY_LAYOUT({
      .sizing =
        {
          .width  = CLAY_SIZING_GROW(),
          .height = CLAY_SIZING_FIXED(60),
        },
      /*.padding = {16},*/
      .childAlignment =
        {
          .x = CLAY_ALIGN_X_CENTER,
          .y = CLAY_ALIGN_Y_CENTER,
        },
    })
  ) {
    // Navigation bar buttons
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
    RenderNavBarButton(CLAY_STRING("[about]"));
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
    RenderNavBarButton(CLAY_STRING("[skills]"));
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
    RenderNavBarButton(CLAY_STRING("[projects]"));
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
    RenderNavBarButton(CLAY_STRING("[education]"));
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
    RenderNavBarButton(CLAY_STRING("[profiles]"));
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
    RenderNavBarButton(CLAY_STRING("[contact]"));
    CLAY(CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW()}})) {}
  };
}
