/*
 *
 * @file  Snake.cpp
 * @biref This file contains the implementation of Snake class.
 *
 */

#include "../include/Snake.hpp"

#include <iostream>
#include <cmath>

Snake::Snake(): head_direction(right), speed(150.f)
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

void Snake::shiftPositions(sf::Sprite& first_sprite, sf::Sprite& second_sprite, const Direction& direction)
{
    sf::Vector2f position = first_sprite.getPosition();

    if (direction == right)
    {
        second_sprite.setPosition(position.x - 40, position.y);
    }
    else if (direction == left)
    {
        second_sprite.setPosition(position.x + 40, position.y);
    }
    else if (direction == up)
    {
        second_sprite.setPosition(position.x, position.y + 40);
    }
    else if (direction == down)
    {
        second_sprite.setPosition(position.x, position.y - 40);
    }
}

void Snake::fixAlignmentErrors()
{
    if (head_direction == body_directions[0])
    {
        shiftPositions(head_sprite, body_sprites[0], head_direction);
    }

    for (unsigned int i = 1; i < body_sprites.size(); i++)
    {
        if (body_directions[i - 1] == body_directions[i])
        {
            shiftPositions(body_sprites[i - 1], body_sprites[i], body_directions[i - 1]);
        }
    }
}

sf::Sprite& Snake::getHeadSprite()
{
    return head_sprite;
}

std::vector<sf::Sprite>& Snake::getBodySprites()
{
    return body_sprites;
}

void Snake::growSnake()
{
    Direction direction = body_directions.back();
    body_directions.push_back(direction);

    sf::Vector2f position = body_sprites.back().getPosition();

    body_sprites.push_back(sf::Sprite(body_texture));
    body_sprites.back().setOrigin(sf::Vector2f(20, 20));

    if (direction == right)
    {
        body_sprites.back().setPosition(sf::Vector2f(position.x - 40, position.y));
    }
    else if (direction == left)
    {
        body_sprites.back().setPosition(sf::Vector2f(position.x + 40, position.y));
    }
    else if (direction == up)
    {
        body_sprites.back().setPosition(sf::Vector2f(position.x, position.y + 40));
    }
    else if (direction == down)
    {
        body_sprites.back().setPosition(sf::Vector2f(position.x, position.y - 40));
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

    fixAlignmentErrors();
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
