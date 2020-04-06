/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.hpp
*/

/**
 * @file Transform.hpp
 * @brief Transform component
 */

#ifndef OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP
#define OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP

#include "../ecs/AComponent.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {
/**
 * @class Class of transform component
 *
 */
class Transform : public ecs::AComponent {
  public:
    /**
     * @brief position : Coordinate of the entity
     *
     */
    type::Vector2D position;
    /**
     * @brief layer : Layer level of the entity
     *
     */
    int layer;

  public:
    /**
     * @brief Constructor of Transform
     *
     * @param entity : Entity that the component belongs to
     * @param position : Coordinate of the entity
     * @param layer : Layer level of the entity
     */
    Transform(ecs::Entity& entity, type::Vector2D position, int layer);
    /**
     * @brief Destructor of Transform
     *
     */
    ~Transform() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP
