/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Render.cpp
*/

#include "Render.hpp"

sfml::component::Render::Render(
    engine::ecs::Entity &entity, std::vector<std::string> &paths)
    : engine::component::ARender(entity, paths)
{
    texture.loadFromFile(paths[1]);
    sprite.setTexture(texture);
}
