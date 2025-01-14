#define CLAY_IMPLEMENTATION
#include "clay/clay.h"
#include "constants.h"
#include "greeting.h"
#include "navigation_bar.h"
#include "portfolio.h"

double windowWidth = 1024, windowHeight = 768;

Clay_RenderCommandArray CreateLayout() {
  Clay_BeginLayout();

  // Build UI here
  CLAY(
    CLAY_ID("MainContainer"),
    CLAY_RECTANGLE({
      .color = PRIMARY_BACKGOUND,
    }),
    CLAY_LAYOUT({
      .sizing          = {CLAY_SIZING_GROW(0)},
      .layoutDirection = CLAY_TOP_TO_BOTTOM,
    })
  ) {
    // Child content go here
    /* Navigation Bar */
    NavigationBar();

    /* Main Content */
    CLAY(CLAY_ID("Main"), CLAY_LAYOUT({.sizing = {CLAY_SIZING_GROW(0)}})) {
      Greeting({CLAY_SIZING_GROW(0)});
    };
  };

  return Clay_EndLayout();
}

CLAY_WASM_EXPORT("UpdateDrawFrame");
Clay_RenderCommandArray UpdateDrawFrame(
  float width, float height, float mouseWheelX, float mouseWheelY,
  float mousePositionX, float mousePositionY, bool isTouchDown,
  bool isMouseDown, bool arrowKeyDownPressedThisFrame,
  bool arrowKeyUpPressedThisFrame, bool dKeyPressedThisFrame, float deltaTime
) {

  windowWidth  = width;
  windowHeight = height;
  Clay_SetLayoutDimensions((Clay_Dimensions) {width, height});
  /*Clay_ScrollContainerData scrollContainerData =
   * Clay_GetScrollContainerData(*/
  /*  Clay_GetElementId(CLAY_STRING("OuterScrollContainer"))*/
  /*);*/
  /*Clay_LayoutElementHashMapItem *perfPage = Clay__GetHashMapItem(*/
  /*  Clay_GetElementId(CLAY_STRING("PerformancePageOuter")).id*/
  /*);*/

  return CreateLayout();
}

int main(int argc, char *argv[]) {
  /*if (argc < 2) {*/
  /*  std::cout << argv[0] << " Version " << portfolio_VERSION_MAJOR << "."*/
  /*            << portfolio_VERSION_MINOR << std::endl;*/
  /*  std::cout << "Usage: " << argv[0] << " TODO" << std::endl;*/
  /*}*/
  /**/
  /*InitializeClay();*/
  /**/
  /*while (WindowShouldNotClose()) {*/
  /*  // Set layout dimensions every frame so that resize works properly*/
  /*  Clay_SetLayoutDimensions((Clay_Dimensions*/
  /*  ) {.width  = static_cast<float>(MyGetScreenWidth()),*/
  /*     .height = static_cast<float>(MyGetScreenHeight())});*/
  /**/
  /*  Clay_Sizing { CLAY_SIZING_GROW(0) } = {*/
  /*    .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW()*/
  /*  };*/
  /**/
  /*  Clay_BeginLayout();*/
  /**/
  /*  // Build UI here*/
  /*  CLAY(*/
  /*    CLAY_ID("MainContainer"),*/
  /*    CLAY_RECTANGLE({*/
  /*      .color = PRIMARY_BACKGOUND,*/
  /*    }),*/
  /*    CLAY_LAYOUT({*/
  /*      .sizing          = { CLAY_SIZING_GROW(0) },*/
  /*      .layoutDirection = CLAY_TOP_TO_BOTTOM,*/
  /*    })*/
  /*  ) {*/
  /*    // Child content go here*/
  /* Navigation Bar */
  /*    NavigationBar();*/
  /**/
  /* Main Content */
  /*    CLAY(CLAY_ID("Main"), CLAY_LAYOUT({.sizing = { CLAY_SIZING_GROW(0) }}))
   * {*/
  /*      Greeting({ CLAY_SIZING_GROW(0) });*/
  /*    };*/
  /*  };*/
  /**/
  /*  Render();*/
  /*}*/
  return 0;
}
