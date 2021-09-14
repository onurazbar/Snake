/*
 *
 * @file  Fruit.hpp
 * @brief This file defines Fruit class.
 *
 */

#ifndef FRUIT_HPP_INCLUDED
#define FRUIT_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class Fruit
{
private:

    /**
     * @brief Texture of the fruit.
     */
    sf::Texture texture;

    /**
     * @brief Sprite of the fruit.
     */
    sf::Sprite sprite;

public:

    /**
     * @brief Default constrcutor.
     */
    Fruit();

    /**
     * @brief Destructor.
     */
    ~Fruit();

    /**
     * @brief Gets sprite of the fruit.
     * @return Returns sprite.
     */
    sf::Sprite& getSprite();

    /**
     * @brief Draws the fruit on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);

    /**
     * @brief Relocates the fruit.
     */
    void relocate();
};

#endif /* FRUIT_HPP_INCLUDED */
