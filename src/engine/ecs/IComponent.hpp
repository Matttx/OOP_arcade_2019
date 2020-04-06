/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ICOMPONENT_HPP
#define OOP_ARCADE_2019_ECS_ICOMPONENT_HPP

#include "Entity.hpp"

namespace engine {

namespace ecs {
/**
 * @class IComponent
 *
 */
class IComponent {
  public:
    /**
     * @brief Destroy the IComponent object
     *
     */
    virtual ~IComponent() = 0;

  public:
    /**
     * @brief Get the Entity object : pure virtual function that permite child to get an entity
     *
     * @return Entity& : return a reference to an Entity
     */
    virtual Entity& getEntity() const = 0;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ICOMPONENT_HPP
