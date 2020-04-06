/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Motion.hpp
*/

/**
 * @file Motion.hpp
 * @brief Motion component
 */

#ifndef OOP_ARCADE_2019_COMPONENT_MOTION_HPP
#define OOP_ARCADE_2019_COMPONENT_MOTION_HPP

#include "../ecs/AComponent.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {
/**
 * @class Class of motion component
 *
 */
class Motion : public ecs::AComponent {
  public:
    /**
     * @brief velocity : vector2D that correspond at the direction of the movement of an entity
     *
     */
    engine::type::Vector2D velocity;
    /**
     * @brief acceleration : vector2D that correspond at the speed of the movement
     *
     */
    engine::type::Vector2D acceleration;

  public:
    /**
     * @brief Construct a new Motion object
     *
     * @param entity : the entity that the component belongs to
     * @param velocity : vector2D that correspond at the direction of the movement of an entity
     * @param acceleration : vector2D that correspond at the speed of the movement
     */
    Motion(ecs::Entity& entity, type::Vector2D velocity, type::Vector2D acceleration);
    /**
     * @brief Destroy the Motion object
     *
     */
    ~Motion() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_MOTION_HPP
