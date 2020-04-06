/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Vector2D.hpp
*/

/**
 * @file Vector2D.hpp
 * @brief Vector2D type
 */

#ifndef OOP_ARCADE_2019_TYPE_VECTOR2D_HPP
#define OOP_ARCADE_2019_TYPE_VECTOR2D_HPP

namespace engine {

namespace type {
/**
 * @class Class of vector type
 *
 */
class Vector2D {
  public:
    /**
     * @brief Constructor of Vector2D
     *
     * @param x X coordinate
     * @param y Y coordinate
     */
    Vector2D(int x, int y) : x(x), y(y) {};
    /**
     * @brief x : X coordinate
     *
     */
    int x;
    /**
     * @brief y : Y coordinate
     *
     */
    int y;
};

} // namespace type

} // namespace engine

#endif // OOP_ARCADE_2019_TYPE_VECTOR2D_HPP
