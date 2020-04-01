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

class IComponent {
  public:
    virtual ~IComponent() = 0;

  public:
    virtual Entity& getEntity() const = 0;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ICOMPONENT_HPP
