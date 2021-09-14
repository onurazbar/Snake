/*
 *
 * @file  MessageBox.hpp
 * @brief This file defines MessageBox class.
 *
 */

#ifndef MESSAGEBOX_HPP_INCLUDED
#define MESSAGEBOX_HPP_INCLUDED

#include <SFML/Graphics.hpp>

class MessageBox
{
private:

    /**
     * @brief Rectangle of the message box.
     */
    sf::RectangleShape rectangle;

    /**
     * @brief Text of the message box.
     */
    sf::Text message_text;

    /**
     * @brief Font of the message box.
     */
    sf::Font font;

public:

    /**
     * @brief Default constrcutor.
     */
    MessageBox();

    /**
     * @brief Destructor.
     */
    ~MessageBox();

    /**
     * @brief Draws the fruit on window.
     * @param window Main game window.
     * @param score Score of the game.
     */
    void draw(sf::RenderWindow& window, const int& score);
};

#endif /* MESSAGEBOX_HPP_INCLUDED */
