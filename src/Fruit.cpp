/*
 *
 * @file  Fruit.cpp
 * @biref This file contains the implementation of Fruit class.
 *
 */

#include "../include/Fruit.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>

Fruit::Fruit()
{
    if (!texture.loadFromFile("../images/fruit.png"))
    {
        throw "Could not load the image \"fruit.png\"!";
    }

    std::srand(std::time(0));

    sprite.setTexture(texture);
    sprite.setOrigin(sf::Vector2f(20, 20));

    relocate();
}

Fruit::~Fruit()
{
}

sf::Sprite& Fruit::getSprite()
{
    return sprite;
}

void Fruit::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Fruit::relocate()
{
    int x = (std::rand() % 1300) + 60;
    int y = (std::rand() % 800) + 60;

    sprite.setPosition(sf::Vector2f(x, y));
}
