/*
 *
 * @file  Animation.hpp
 * @brief This file defines Animation class.
 *
 */

#ifndef ANIMATION_HPP_INCLUDED
#define ANIMATION_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <array>

class Animation
{
private:

    /**
     * @brief Number fo frames.
     */
    int frames_number;

    /**
     * @brief Animation duration.
     */
    float animation_duration;

    /**
     * @brief Size of each sprite.
     */
    sf::Vector2f sprite_size;

    /**
     * @brief Texture of the animation.
     */
    sf::Texture texture;

    /**
     * @brief Sprites of the animation for rendering.
     */
    std::array<sf::Sprite, 100> sprites;

public:

    /**
     * @brief Default constrcutor.
     */
    Animation();

    /**
     * @brief Destructor.
     */
    ~Animation();

    /**
     * @brief Updates the current frame of the animation.
     * @param elapsed_time Elapsed time.
     */
    void updateFrame(const sf::Time& elapsed_time);

    /**
     * @brief Draws animation on window.
     * @param window Main game window.
     */
    void draw(sf::RenderWindow& window);
};

#endif /* ANIMATION_HPP_INCLUDED */
