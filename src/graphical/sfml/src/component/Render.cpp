/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.cpp
*/

#include "Render.hpp"

#include "../../../IGraphical.hpp"

sfml::component::Render::Render(
    engine::ecs::Entity &entity, const std::vector<std::string> &paths)
    : engine::component::ARender(entity, paths)
{
    if (!texture.loadFromFile(paths[LIBTYPE::GRAPHIC]))
        throw std::runtime_error("SFML: Can't load image");
    sprite.setTexture(texture);
    srcRect.width = texture.getSize().x;
    srcRect.height = texture.getSize().y;
}
