/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animation.hpp
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
     * @brief Construct a new Animation object
     *
     * @param row
     * @param frames
     * @param speed
     */
    Animation(int row, int frames, int speed) : row(row), frames(frames), speed(speed) {};
    /**
     * @brief row : number of rows for the animation
     *
     */
    int row;
    /**
     * @brief frames : number of frames for the animation
     *
     */
    int frames;
    /**
     * @brief speed : the speed of the animation
     *
     */
    int speed;
};

} // namespace type

} // namespace engine

#endif // OOP_ARCADE_2019_TYPE_ANIMATION_HPP
