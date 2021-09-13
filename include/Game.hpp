/*
 *
 * @file  Game.hpp
 * @brief This file defines Game class.
 *
 */

#ifndef GAME_HPP_INCLUDED
#define GAME_HPP_INCLUDED

#include "Animation.hpp"
#include "Snake.hpp"

class Game
{
private:

    /**
     * @brief Main game window.
     */
    sf::RenderWindow window;

    /**
     * @brief Fire animation on the walls.
     */
    Animation fire_animation;

    /**
     * @brief Snake of the game.
     */
    Snake snake;

public:

    /**
     * @brief Default constrcutor.
     */
    Game();

    /**
     * @brief Destructor.
     */
    ~Game();

    /**
     * @brief Starts the gameplay.
     */
    void play();
};

#endif /* GAME_HPP_INCLUDED */
