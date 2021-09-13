/*
 *
 * @file  Snake.cpp
 * @biref This file contains the implementation of Snake class.
 *
 */

#include "../include/Snake.hpp"

Snake::Snake()
{
    if (!head_texture.loadFromFile("../images/snake_head.png"))
    {
        throw "Could not load the image \"snake_head.png\"!";
    }

    if (!body_texture.loadFromFile("../images/snake_body.png"))
    {
        throw "Could not load the image \"snake_body.png\"!";
    }

    head_sprite.setTexture(head_texture);
    head_sprite.setOrigin(sf::Vector2f(20, 20));
    head_sprite.setPosition(sf::Vector2f(280, 200));

    for (int i = 0; i < 3; i++)
    {
        body_sprites.push_back(sf::Sprite(body_texture));
        body_sprites[i].setOrigin(sf::Vector2f(20, 20));
        body_sprites[i].setPosition(sf::Vector2f(240 - (40 * i), 200));
    }
}

Snake::~Snake()
{
}

void Snake::draw(sf::RenderWindow& window)
{
    window.draw(head_sprite);

    for (auto& sprite : body_sprites)
    {
        window.draw(sprite);
    }
}
