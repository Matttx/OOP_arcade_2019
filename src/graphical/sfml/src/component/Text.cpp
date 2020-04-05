/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text.cpp
*/

#include "Text.hpp"

#include "../../../IGraphical.hpp"

sfml::component::Text::Text(engine::ecs::Entity& entity,
    const std::string& text, const std::vector<std::string>& paths)
    : engine::component::AText(entity, text, paths)
{
    if (!font.loadFromFile(paths[LIBTYPE::GRAPHIC]))
        throw std::exception();
    this->text.setString(text);
    this->text.setFont(font);
}
