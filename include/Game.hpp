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
#include "Fruit.hpp"
#include "MessageBox.hpp"

class Game
{
private:

    /**
     * @brief Indicates whether the game is ovver or not.
     */
    bool game_over;

    /**
     * @brief Score of the game.
     */
    int score;

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

    /**
     * @brief Fruit of the game.
     */
    Fruit fruit;

    /**
     * @brief Message box for game over case.
     */
    MessageBox message_box;

    /**
     * @brief Checks whether snake touches the fruit or not.
     */
    void checkFruitEating();

    /**
     * @brief Checks whether snake touches the fire or itself.
     */
    void checkGameOver();

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
