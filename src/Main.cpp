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
    try
    {
        std::cout << "Snake game!" << std::endl;

        auto game = std::make_unique<Game>();

        game->play();
    }
    catch (const char* ex)
    {
        std::cerr << ex << std::endl;
    }
    catch (const std::exception& ex)
    {
        std::cerr << ex.what() << std::endl;
    }
    catch (...)
    {
        std::cerr << "Exception occured!" << std::endl;
    }

    return 0;
}
