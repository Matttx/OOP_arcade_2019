/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.hpp
*/

#ifndef OOP_ARCADE_2019_TRANSFORM_HPP
#define OOP_ARCADE_2019_TRANSFORM_HPP

#include "type/Vector2D.hpp"

namespace engine { namespace component {
class Transform : public engine::ecs::AComponent {
public:
    Transform(engine::ecs::Entity& entity, engine::type::Vector2D position, int layer);
    ~Transform();
    engine::type::Vector2D position;
    int layer;
};
} }

#endif // OOP_ARCADE_2019_TRANSFORM_HPP
