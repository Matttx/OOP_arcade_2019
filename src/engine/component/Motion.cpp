/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Motion.cpp
*/

#include "Motion.hpp"

engine::component::Motion::Motion(engine::ecs::Entity& entity,
    engine::type::Vector2D velocity, engine::type::Vector2D acceleration)
    : AComponent(entity), velocity(velocity), acceleration(acceleration)
{
}

engine::component::Motion::~Motion() = default;
