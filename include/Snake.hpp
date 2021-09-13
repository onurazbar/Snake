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

class Snake
{
private:

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
};

#endif /* SNAKE_HPP_INCLUDED */
