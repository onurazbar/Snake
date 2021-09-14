/*
 *
 * @file  MessageBox.cpp
 * @biref This file contains the implementation of MessageBox class.
 *
 */

#include "../include/MessageBox.hpp"

MessageBox::MessageBox()
{
    rectangle.setSize(sf::Vector2f(600, 200));
    rectangle.setFillColor(sf::Color(150, 220, 240));
    rectangle.setOrigin(sf::Vector2f(300, 100));
    rectangle.setPosition(sf::Vector2f(735, 459));

    if (!font.loadFromFile("../fonts/open-sans/OpenSans-Regular.ttf"))
    {
        throw "Could not load the font \"OpenSans-Regular.ttf\"!";
    }
}

MessageBox::~MessageBox()
{
}

void MessageBox::draw(sf::RenderWindow& window, const int& score)
{
    window.draw(rectangle);

    std::string str("Game is over your score: ");
    str.append(std::to_string(score));
    str.append("\nGame will be closed in 5 seconds");

    message_text.setString(str);
    message_text.setFont(font);
    message_text.setPosition(sf::Vector2f(510, 410));
    message_text.setCharacterSize(30);
    message_text.setFillColor(sf::Color::Black);

    window.draw(message_text);
}
