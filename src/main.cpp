#include <cstdlib>
#include <iostream>

#define CLAY_IMPLEMENTATION
#include "clay/clay.h"

#include "clay/renderers/raylib/clay_renderer_raylib.c"

#include "portfolio.h"

// This function is new since the video was published
void HandleClayErrors(Clay_ErrorData errorData) {
  std::cerr << errorData.errorText.chars;
}

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << portfolio_VERSION_MAJOR << "."
              << portfolio_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " TODO" << std::endl;
  }

  Clay_Raylib_Initialize(1024, 768, "Introduction to Clay",
                         FLAG_WINDOW_RESIZABLE);

  uint64_t clayRequiredMemory = Clay_MinMemorySize();
  std::cout << clayRequiredMemory << std::endl;

  Clay_Arena clayMemory =
      (Clay_Arena){.capacity = clayRequiredMemory,
                   .memory = (char *)malloc((size_t)1024 * 1024 * 1024 * 1024)};

  std::cout << "Hello" << std::endl;

  Clay_Initialize(clayMemory,
                  (Clay_Dimensions){.width = (float)GetScreenWidth(),
                                    .height = (float)GetScreenHeight()},
                  (Clay_ErrorHandler){HandleClayErrors});

  std::cout << "Hello" << std::endl;

  while (!WindowShouldClose()) {
    // Set layout dimensions every frame so that resize works properly
    Clay_SetLayoutDimensions(
        (Clay_Dimensions){.width = static_cast<float>(GetScreenWidth()),
                          .height = static_cast<float>(GetScreenHeight())});

    std::cout << "Hello" << std::endl;

    Clay_BeginLayout();

    // Build UI here
    CLAY(CLAY_RECTANGLE({.color = {255, 0, 0, 255}}),
         CLAY_LAYOUT({.sizing = {.width = CLAY_SIZING_GROW(),
                                 .height = CLAY_SIZING_GROW()}})) {}

    Clay_RenderCommandArray renderCommands = Clay_EndLayout();

    BeginDrawing();
    ClearBackground(BLACK);
    Clay_Raylib_Render(renderCommands);
    EndDrawing();
  }

  std::cout << "Hello World" << std::endl;
  return 0;
}
