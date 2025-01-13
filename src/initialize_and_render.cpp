#include "initialize_and_render.h"

#include "clay/clay.h"

#define CLAY_RAYLIB_IMPLEMENTATION
#include "clay/renderers/raylib/clay_renderer_raylib.h"
#include "clay/renderers/raylib/raylib.h"
#include "constants.h"

#include <cstdlib>
#include <iostream>

Raylib_Font Raylib_fonts[10];
Camera Raylib_camera;

void HandleClayErrors(Clay_ErrorData errorData) {
  std::cerr << errorData.errorText.chars;
}

void InitializeClay() {
  Clay_Raylib_Initialize(
    1280, 720, "Introduction to Clay", FLAG_WINDOW_RESIZABLE
  );

  uint64_t clay_required_memory = Clay_MinMemorySize();
  std::cout << "[PORTFOLIO] Clay Required Memory: " << clay_required_memory
            << std::endl;

  Clay_Arena clay_memory = Clay_CreateArenaWithCapacityAndMemory(
    clay_required_memory, malloc(clay_required_memory)
  );

  Clay_Initialize(
    clay_memory,
    (Clay_Dimensions) {.width  = static_cast<float>(GetScreenWidth()),
                       .height = static_cast<float>(GetScreenHeight())},
    (Clay_ErrorHandler) {HandleClayErrors}
  );

  /* Font */
  Clay_SetMeasureTextFunction(Raylib_MeasureText);

  Raylib_fonts[FONT_ID_BODY_24] = (Raylib_Font) {
    .fontId = FONT_ID_BODY_24,
    .font   = LoadFontEx(
      "/usr/share/fonts/TTF/HackNerdFontMono-Regular.ttf", 24, 0, 400
    ),
  };
}

bool WindowShouldNotClose() { return !WindowShouldClose(); }

int MyGetScreenWidth() { return GetScreenWidth(); }
int MyGetScreenHeight() { return GetScreenHeight(); }

void Render() {
  Clay_RenderCommandArray renderCommands = Clay_EndLayout();

  BeginDrawing();
  ClearBackground(BLACK);
  Clay_Raylib_Render(renderCommands);
  EndDrawing();
}
