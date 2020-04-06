/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animation.hpp
*/

/**
 * @brief Animation type
 */

#ifndef OOP_ARCADE_2019_TYPE_ANIMATION_HPP
#define OOP_ARCADE_2019_TYPE_ANIMATION_HPP

namespace engine {

namespace type {
/**
 * @class Animation
 *
 */
class Animation {
  public:
    /**
     * @brief Constructor of Animation
     *
     * @param row Row where the animation is
     * @param frames Total frames of the animation
     * @param speed Speed of the animation in milliseconds
     */
    Animation(int row, int frames, int speed) : row(row), frames(frames), speed(speed) {};
    /**
     * @brief row : Row where the animation is
     *
     */
    int row;
    /**
     * @brief frames : Total frames of the animation
     *
     */
    int frames;
    /**
     * @brief speed : Speed of the animation in milliseconds
     *
     */
    int speed;
};

} // namespace type

} // namespace engine

#endif // OOP_ARCADE_2019_TYPE_ANIMATION_HPP
