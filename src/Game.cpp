/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of Game class.
 *
 */

#include "../include/Game.hpp"

#include <iostream>
#include <string>

Game::Game(): game_over(false), score(0)
{
    window.create(sf::VideoMode(1470, 918), "Snake Game  -  Score: 0");
}

Game::~Game()
{
}

void Game::checkFruitEating()
{
    if (snake.getHeadSprite().getGlobalBounds().intersects(fruit.getSprite().getGlobalBounds()))
    {
        score++;

        std::string str("Snake Game  -  Score: ");
        str.append(std::to_string(score));
        window.setTitle(str.c_str());

        snake.growSnake();
        fruit.relocate();
    }
}

void Game::checkGameOver()
{
    std::array<sf::Sprite, 100> fire_sprites = fire_animation.getSprites();

    for (auto& fire_sprite : fire_sprites)
    {
        if (snake.getHeadSprite().getGlobalBounds().intersects(fire_sprite.getGlobalBounds()))
        {
            game_over = true;
        }
    }

    std::vector<sf::Sprite> body_sprites = snake.getBodySprites();

    for (unsigned int i = 2; i < body_sprites.size(); i++)
    {
        if (snake.getHeadSprite().getGlobalBounds().intersects(body_sprites[i].getGlobalBounds()))
        {
            game_over = true;
        }
    }
}

void Game::play()
{
    std::cout << "Game::play()" << std::endl;

    sf::Time elapsed_time;
    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;
        sf::Time delta_time = clock.restart();

        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    window.close();
                    break;

                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Right)
                    {
                        snake.changeDirection(right);
                    }
                    else if (event.key.code == sf::Keyboard::Left)
                    {
                        snake.changeDirection(left);
                    }
                    else if (event.key.code == sf::Keyboard::Up)
                    {
                        snake.changeDirection(up);
                    }
                    else if (event.key.code == sf::Keyboard::Down)
                    {
                        snake.changeDirection(down);
                    }
                    else if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.close();
                    }
                    break;

                default:
                    break;
            }
        }

        elapsed_time += delta_time;

        fire_animation.updateFrame(elapsed_time);
        snake.move(delta_time);

        checkFruitEating();
        checkGameOver();

        window.clear(sf::Color::White);

        fire_animation.draw(window);
        fruit.draw(window);
        snake.draw(window);

        if (game_over)
        {
            message_box.draw(window, score);
        }

        window.display();

        if (game_over)
        {
            sf::sleep(sf::milliseconds(5000));
            window.close();
        }
    }
}
