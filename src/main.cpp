#include <cstdlib>
#include <iostream>

#define CLAY_IMPLEMENTATION
#include "clay/clay.h"
#include "clay/renderers/raylib/clay_renderer_raylib.c"
#include "portfolio.h"

const int FONT_ID_BODY_16 = 0;

Clay_Color PRIMARY_BACKGOUND   = {34, 40, 49, 255};
Clay_Color SECONDARY_BACKGOUND = {49, 54, 63, 255};
Clay_Color PRIMARY             = {238, 238, 238, 255};
Clay_Color SECONDARY           = {118, 171, 174, 255};

void HandleClayErrors(Clay_ErrorData errorData) {
  std::cerr << errorData.errorText.chars;
}

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

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << portfolio_VERSION_MAJOR << "."
              << portfolio_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " TODO" << std::endl;
  }

  Clay_Raylib_Initialize(
    1280, 720, "Introduction to Clay", FLAG_WINDOW_RESIZABLE
  );

  uint64_t clayRequiredMemory = Clay_MinMemorySize();
  std::cout << "[PORTFOLIO] Clay Required Memory: " << clayRequiredMemory
            << std::endl;

  Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(
    clayRequiredMemory, malloc(clayRequiredMemory)
  );

  Clay_Initialize(
    clayMemory,
    (Clay_Dimensions) {.width  = static_cast<float>(GetScreenWidth()),
                       .height = static_cast<float>(GetScreenHeight())},
    (Clay_ErrorHandler) {HandleClayErrors}
  );

  Clay_SetMeasureTextFunction(Raylib_MeasureText);

  Raylib_fonts[FONT_ID_BODY_16] = (Raylib_Font) {
    .fontId = FONT_ID_BODY_16,
    .font   = LoadFontEx(
      "/usr/share/fonts/TTF/HackNerdFontMono-Regular.ttf", 48, 0, 400
    ),
  };

  while (!WindowShouldClose()) {
    // Set layout dimensions every frame so that resize works properly
    Clay_SetLayoutDimensions((Clay_Dimensions
    ) {.width  = static_cast<float>(GetScreenWidth()),
       .height = static_cast<float>(GetScreenHeight())});

    Clay_Sizing layoutExpand = {
      .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW()
    };

    Clay_BeginLayout();

    // Build UI here
    CLAY(
      CLAY_ID("MainContainer"),
      CLAY_RECTANGLE({
        .color = PRIMARY_BACKGOUND,
      }),
      CLAY_LAYOUT({
        .sizing          = layoutExpand,
        .layoutDirection = CLAY_TOP_TO_BOTTOM,
      })
    ) {
      // Child content go here
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

      /* Main Content */
      CLAY(CLAY_ID("Main"), CLAY_LAYOUT({.sizing = layoutExpand})) {};
    };

    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(renderCommands);
    EndDrawing();
  }
  return 0;
}
