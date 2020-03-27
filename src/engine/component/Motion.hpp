/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Motion.hpp
*/

#ifndef OOP_ARCADE_2019_MOTION_HPP
#define OOP_ARCADE_2019_MOTION_HPP

#include "engine/type/Vector2D.hpp"

namespace engine { namespace component {
class Motion : public engine::ecs::AComponent {
public:
    Motion(engine::ecs::Entity& entity, engine::type::Vector2D velocity, engine::type::Vector2D acceleration)
    engine::type::Vector2D velocity;
    engine::type::Vector2D acceleration;
};
}}

#endif // OOP_ARCADE_2019_MOTION_HPP
