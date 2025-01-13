#define CLAY_IMPLEMENTATION
#include "clay/clay.h"
#include "constants.h"
#include "greeting.h"
#include "initialize_and_render.h"
#include "navigation_bar.h"
#include "portfolio.h"

#include <cstdlib>
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << portfolio_VERSION_MAJOR << "."
              << portfolio_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " TODO" << std::endl;
  }

  InitializeClay();

  while (WindowShouldNotClose()) {
    // Set layout dimensions every frame so that resize works properly
    Clay_SetLayoutDimensions((Clay_Dimensions
    ) {.width  = static_cast<float>(MyGetScreenWidth()),
       .height = static_cast<float>(MyGetScreenHeight())});

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
      NavigationBar();

      /* Main Content */
      CLAY(CLAY_ID("Main"), CLAY_LAYOUT({.sizing = layoutExpand})) {
        Greeting(layoutExpand);
      };
    };

    Render();
  }
  return 0;
}
