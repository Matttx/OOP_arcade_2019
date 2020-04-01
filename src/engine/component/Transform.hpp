/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP
#define OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP

#include "../ecs/AComponent.hpp"
#include "../ecs/Entity.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {

class Transform : public ecs::AComponent {
  public:
    type::Vector2D position;
    int layer;

  public:
    Transform(ecs::Entity& entity, type::Vector2D position, int layer);
    ~Transform() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_TRANSFORM_HPP
