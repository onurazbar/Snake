/*
 *
 * @file  Snake.hpp
 * @brief This file defines Snake class.
 *
 */

#ifndef SNAKE_HPP_INCLUDED
#define SNAKE_HPP_INCLUDED

#include <SFML/Graphics.hpp>

#include <vector>

enum Direction
{
    right,
    left,
    up,
    down
};

class Snake
{
private:

    /**
     * @brief Current direction of the snake head.
     */
    Direction head_direction;

    /**
     * @brief Current directions of the snake bofy nodes.
     */
    std::vector<Direction> body_directions;

    /**
     * @brief Speed of the snake.
     */
    float speed;

    /**
     * @brief Texture of the snake's head.
     */
    sf::Texture head_texture;

    /**
     * @brief Texture of the snake's body.
     */
    sf::Texture body_texture;

    /**
     * @brief Sprite of the snake's head.
     */
    sf::Sprite head_sprite;

    /**
     * @brief Sprites of the snake's body nodes.
     */
    std::vector<sf::Sprite> body_sprites;

    /**
     * @brief Performs math of the sprite move.
     * @param direction Direction of the sprite.
     * @param time_seconds delta time in seconds.
     */
    sf::Vector2f decideMove(const Direction& direction, const float& time_seconds);

    /**
     * @brief Fixes position shift errors.
     */
    void fixPositionShifts();

public:

    /**
     * @brief Default constrcutor.
     */
    Snake();

    /**
     * @brief Destructor.
     */
    ~Snake();

    /**
     * @brief Draws animation on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Moves the snake according to current direction.
     * @param delta_time Time elapsed since last frame.
     */
    void move(const sf::Time& delta_time);

    /**
     * @brief Decides the direction and rotation of the sprite according to keyboard inputs.
     * @param direction Direction that is decided by player.
     */
    void changeDirection(const Direction& direction);
};

#endif /* SNAKE_HPP_INCLUDED */
