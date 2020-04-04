/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AText.cpp
*/

#include "AText.hpp"

engine::component::AText::AText(
    engine::ecs::Entity& entity, const std::string& text, const std::vector<std::string>& paths)
    : engine::ecs::AComponent(entity), text(text), paths(paths)
{
}

engine::component::AText::~AText() = default;