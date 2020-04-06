/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Transform.cpp
*/

#include "Transform.hpp"

engine::component::Transform::Transform(engine::ecs::Entity &entity, engine::type::Vector2D position, int layer)
    : engine::ecs::AComponent(entity), position(position), layer(layer)
{
}

engine::component::Transform::~Transform() = default;
