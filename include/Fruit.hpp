/*
 *
 * @file  Fruit.hpp
 * @brief This file defines Fruit class.
 *
 */

#ifndef FRUIT_HPP__INCLUDED
#define FRUIT_HPP__INCLUDED

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
     * @brief Draws the fruit on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);
};

#endif /* FRUIT_HPP__INCLUDED */
