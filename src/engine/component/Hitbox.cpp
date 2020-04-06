/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Hitbox.cpp
*/

#include "Hitbox.hpp"

engine::component::Hitbox::Hitbox(engine::ecs::Entity& entity, int width, int height)
    : AComponent(entity), width(width), height(height)
{
}

engine::component::Hitbox::~Hitbox() = default;
