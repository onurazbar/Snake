/*
 *
 * @file  Snake.cpp
 * @biref This file contains the implementation of Snake class.
 *
 */

#include "../include/Snake.hpp"

#include <iostream>
#include <cmath>

Snake::Snake(): head_direction(right), speed(100.f)
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
        body_directions.push_back(right);
    }
}

Snake::~Snake()
{
}

sf::Vector2f Snake::decideMove(const Direction& direction, const float& time_seconds)
{
    sf::Vector2f offset;

    if (direction == right)
    {
        offset = sf::Vector2f((speed * time_seconds), 0);
    }
    else if (direction == left)
    {
        offset = sf::Vector2f(-(speed * time_seconds), 0);
    }
    else if (direction == up)
    {
        offset = sf::Vector2f(0, -(speed * time_seconds));
    }
    else if (direction == down)
    {
        offset = sf::Vector2f(0, (speed * time_seconds));
    }

    return offset;
}

void Snake::fixPositionShifts()
{
    bool same_direction = true;

    for (auto& direction : body_directions)
    {
        if (direction != head_direction)
        {
            same_direction = false;
            break;
        }
    }

    if (same_direction)
    {
        if (head_direction == right)
        {
            sf::Vector2f head_position = head_sprite.getPosition();
            body_sprites[0].setPosition(head_position.x - 40, head_position.y);

            for (unsigned int i = 1; i < body_sprites.size(); i++)
            {
                sf::Vector2f position = body_sprites[i - 1].getPosition();
                body_sprites[i].setPosition(position.x - 40, position.y);
            }
        }
        else if (head_direction == left)
        {
            sf::Vector2f head_position = head_sprite.getPosition();
            body_sprites[0].setPosition(head_position.x + 40, head_position.y);

            for (unsigned int i = 1; i < body_sprites.size(); i++)
            {
                sf::Vector2f position = body_sprites[i - 1].getPosition();
                body_sprites[i].setPosition(position.x + 40, position.y);
            }
        }
        else if (head_direction == up)
        {
            sf::Vector2f head_position = head_sprite.getPosition();
            body_sprites[0].setPosition(head_position.x, head_position.y + 40);

            for (unsigned int i = 1; i < body_sprites.size(); i++)
            {
                sf::Vector2f position = body_sprites[i - 1].getPosition();
                body_sprites[i].setPosition(position.x, position.y + 40);
            }
        }
        else if (head_direction == down)
        {
            sf::Vector2f head_position = head_sprite.getPosition();
            body_sprites[0].setPosition(head_position.x, head_position.y - 40);

            for (unsigned int i = 1; i < body_sprites.size(); i++)
            {
                sf::Vector2f position = body_sprites[i - 1].getPosition();
                body_sprites[i].setPosition(position.x, position.y - 40);
            }
        }
    }
}

void Snake::draw(sf::RenderWindow& window)
{
    for (auto& sprite : body_sprites)
    {
        window.draw(sprite);
    }

    window.draw(head_sprite);
}

void Snake::move(const sf::Time& delta_time)
{
    float time_seconds = delta_time.asSeconds();

    sf::Vector2f offset = decideMove(head_direction, time_seconds);
    head_sprite.move(offset);

    if (body_directions[0] != head_direction)
    {
        sf::Vector2f head_position = head_sprite.getPosition();
        sf::Vector2f body_position = body_sprites[0].getPosition();

        if ((head_direction == up) || (head_direction == down))
        {
            if (std::abs(head_position.x - body_position.x) < 0.5)
            {
                body_directions[0] = head_direction;
                offset = decideMove(body_directions[0], time_seconds);
            }
        }
        else
        {
            if (std::abs(head_position.y - body_position.y) < 0.5)
            {
                body_directions[0] = head_direction;
                offset = decideMove(body_directions[0], time_seconds);
            }
        }
    }

    offset = decideMove(body_directions[0], time_seconds);
    body_sprites[0].move(offset);

    for (unsigned int i = 1; i < body_sprites.size(); i++)
    {
        if (body_directions[i] != body_directions[i - 1])
        {
            sf::Vector2f body_position1 = body_sprites[i - 1].getPosition();
            sf::Vector2f body_position2 = body_sprites[i].getPosition();

            if ((body_directions[i - 1] == up) || (body_directions[i - 1] == down))
            {
                if (std::abs(body_position1.x - body_position2.x) < 0.5)
                {
                    body_directions[i] = body_directions[i - 1];
                    offset = decideMove(body_directions[i], time_seconds);
                }
            }
            else
            {
                if (std::abs(body_position1.y - body_position2.y) < 0.5)
                {
                    body_directions[i] = body_directions[i - 1];
                    offset = decideMove(body_directions[i], time_seconds);
                }
            }
        }

        offset = decideMove(body_directions[i], time_seconds);
        body_sprites[i].move(offset);
    }

    fixPositionShifts();
}

void Snake::changeDirection(const Direction& direction)
{
    switch (direction)
    {
        case right:
            if (head_direction != left)
            {
                if (head_direction == down)
                {
                    head_sprite.rotate(-90);
                }
                else if (head_direction == up)
                {
                    head_sprite.rotate(90);
                }

                head_direction = right;
            }
            break;

        case left:
            if (head_direction != right)
            {
                if (head_direction == down)
                {
                    head_sprite.rotate(90);
                }
                else if (head_direction == up)
                {
                    head_sprite.rotate(-90);
                }

                head_direction = left;
            }
            break;

        case up:
            if (head_direction != down)
            {
                if (head_direction == right)
                {
                    head_sprite.rotate(-90);
                }
                else if (head_direction == left)
                {
                    head_sprite.rotate(90);
                }

                head_direction = up;
            }
            break;

        case down:
            if (head_direction != up)
            {
                if (head_direction == right)
                {
                    head_sprite.rotate(90);
                }
                else if (head_direction == left)
                {
                    head_sprite.rotate(-90);
                }

                head_direction = down;
            }
            break;

        default:
            break;
    }

}
