/*
 *
 * @file  Game.cpp
 * @biref This file contains the implementation of Game class.
 *
 */

#include "../include/Game.hpp"

#include <iostream>

Game::Game()
{
    window.create(sf::VideoMode(1470, 918), "Snake Game");
}

Game::~Game()
{
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


        window.clear(sf::Color::White);

        fire_animation.draw(window);
        fruit.draw(window);
        snake.draw(window);

        window.display();
    }
}
