/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AComponent.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ACOMPONENT_HPP
#define OOP_ARCADE_2019_ECS_ACOMPONENT_HPP

namespace engine {
namespace ecs {
class Entity;
} // namespace ecs
} // namespace engine

#include "Entity.hpp"

namespace engine {

namespace ecs {

class AComponent {
  public:
    explicit AComponent(Entity& entity);
    virtual ~AComponent() = 0;

  public:
    Entity& getEntity() const;

  private:
    Entity& _entity;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ACOMPONENT_HPP
