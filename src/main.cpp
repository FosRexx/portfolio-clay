#include <iostream>

#include "portfolio.h"

int main (int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << argv[0] << " Version " << portfolio_VERSION_MAJOR << "."
              << portfolio_VERSION_MINOR << std::endl;
    std::cout << "Usage: " << argv[0] << " TODO" << std::endl;
  }
  
  std::cout << "Hello World" << std::endl;
  return 0;
}

