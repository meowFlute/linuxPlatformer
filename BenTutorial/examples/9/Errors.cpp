#include "Errors.h"
#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>

//Prints out an error message and exits the game
void fatalError(std::string errorString) {
    std::cout << errorString << std::endl;
    std::cout << "Enter any key to quit...";
    int tmp;
    std::cin >> tmp;
    SDL_Quit();
    exit(-1); //now we say that -1 means fatal error
}
