/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP
#define OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP

#include "../ecs/AComponent.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {
/**
 * @class Class of component Transform
 * 
 */
class Transform : public ecs::AComponent {
  public:
    /**
     * @brief position : the positions x and y of the render on the screen
     * 
     */
    type::Vector2D position;
    /**
     * @brief layer : layer of the render on the screen
     * 
     */
    int layer;

  public:
    /**
     * @brief Construct a new Transform object
     * 
     * @param entity : the entity that the component belongs to
     * @param position : the positions x and y of the render on the screen
     * @param layer : layer of the render on the screen
     */
    Transform(ecs::Entity& entity, type::Vector2D position, int layer);
    /**
     * @brief Destroy the Transform object
     * 
     */
    ~Transform() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP
