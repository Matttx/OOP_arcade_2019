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
/**
 * @class Vector2D
 *
 */
class Vector2D {
  public:
    /**
     * @brief Construct a new Vector 2 D object
     *
     * @param x
     * @param y
     */
    Vector2D(int x, int y) : x(x), y(y) {};
    /**
     * @brief x : position x
     *
     */
    int x;
    /**
     * @brief y : position y
     *
     */
    int y;
};

} // namespace type

} // namespace engine

#endif // OOP_ARCADE_2019_TYPE_VECTOR2D_HPP
