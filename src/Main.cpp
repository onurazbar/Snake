/*
 *
 * @file Main.cpp
 * @brief This file contains the main function of the snake game.
 *
 */

#include "../include/Game.hpp"

#include <iostream>
#include <memory>

int main()
{
    std::cout << "Snake game!" << std::endl;

    auto game = std::make_unique<Game>();

    game->play();

    return 0;
}
