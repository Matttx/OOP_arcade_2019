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

class Animation {
  public:
    Animation(int row, int frames, int speed): row(row), frames(frames), speed(speed) {};
    int row;
    int frames;
    int speed;
};

} // namespace type

} // namespace engine

#endif // OOP_ARCADE_2019_TYPE_ANIMATION_HPP
