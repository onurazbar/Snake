/*
 *
 * @file  Animation.cpp
 * @biref This file contains the implementation of Animation class.
 *
 */

#include "../include/Animation.hpp"

Animation::Animation(): frames_number(12), animation_duration(0.6f), sprite_size(84, 108)
{
    if (!texture.loadFromFile("../images/fire_flames.png"))
    {
        throw "Could not load the image \"fire_flames.png\"!";
    }

    for (unsigned int i = 0; i < 35; i++)
    {
        sprites[i].setTexture(texture);
        sprites[i].setScale(sf::Vector2f(0.5f, 0.5f));
        sprites[i].setPosition(sf::Vector2f((42 * i), 0));
    }

    for (unsigned int i = 35; i < 70; i++)
    {
        sprites[i].setTexture(texture);
        sprites[i].setScale(sf::Vector2f(0.5f, 0.5f));
        sprites[i].setPosition(sf::Vector2f((42 * (i - 35)), 864));
    }

    for (unsigned int i = 70; i < 85; i++)
    {
        sprites[i].setTexture(texture);
        sprites[i].setScale(sf::Vector2f(0.5f, 0.5f));
        sprites[i].setPosition(sf::Vector2f(0, (54 * (i - 69))));
    }

    for (unsigned int i = 85; i < 100; i++)
    {
        sprites[i].setTexture(texture);
        sprites[i].setScale(sf::Vector2f(0.5f, 0.5f));
        sprites[i].setPosition(sf::Vector2f(1428, (54 * (i - 84))));
    }
}

Animation::~Animation()
{
}

void Animation::updateFrame(const sf::Time& elapsed_time)
{
    float time_seconds = elapsed_time.asSeconds();

    int animation_frame = static_cast<int>((time_seconds / animation_duration) * frames_number) % frames_number;

    for (auto& sprite : sprites)
    {
        sprite.setTextureRect(sf::IntRect((animation_frame  % 4) * sprite_size.x,
                           static_cast<int>(animation_frame / 4) * sprite_size.y, sprite_size.x, sprite_size.y));
    }
}

void Animation::draw(sf::RenderWindow& window)
{
    for (auto& sprite : sprites)
    {
        window.draw(sprite);
    }
}
