/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Vector2D.hpp
*/

#ifndef OOP_ARCADE_2019_TYPE_VECTOR2D_HPP
#define OOP_ARCADE_2019_TYPE_VECTOR2D_HPP

namespace engine {

namespace type {

class Vector2D {
  public:
    Vector2D(int x, int y): x(x), y(y) {};
    int x;
    int y;
};

} // namespace type

} // namespace engine

#endif // OOP_ARCADE_2019_TYPE_VECTOR2D_HPP
