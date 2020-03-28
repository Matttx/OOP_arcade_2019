/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.cpp
*/

#include "Size.hpp"

engine::component::Size::Size(
    engine::ecs::Entity &entity, int width, int height)
    : engine::ecs::AComponent(entity), width(width), height(height)
{
}

engine::component::Size::~Size() = default;
