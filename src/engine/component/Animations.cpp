/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.cpp
*/

#include "Animations.hpp"

engine::component::Animations::Animations(engine::ecs::Entity& entity,
    const std::map<std::string, type::Animation>& list)
    : AComponent(entity), list(list)
{
}

engine::component::Animations::~Animations() = default;
