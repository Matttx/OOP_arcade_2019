/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Motion.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_MOTION_HPP
#define OOP_ARCADE_2019_COMPONENT_MOTION_HPP

#include "../ecs/AComponent.hpp"
#include "../type/Vector2D.hpp"

namespace engine {

namespace component {

class Motion : public ecs::AComponent {
  public:
    engine::type::Vector2D velocity;
    engine::type::Vector2D acceleration;

  public:
    Motion(ecs::Entity& entity, type::Vector2D velocity,
        type::Vector2D acceleration);
    ~Motion() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_MOTION_HPP
