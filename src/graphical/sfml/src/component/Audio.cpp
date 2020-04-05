/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio.cpp
*/

#include "Audio.hpp"

#include "../../../IGraphical.hpp"

sfml::component::Audio::Audio(
    engine::ecs::Entity& entity, const std::vector<std::string>& paths)
    : engine::component::AAudio(entity, paths)
{
    if (!music.openFromFile(paths[LIBTYPE::GRAPHIC]))
        throw std::runtime_error("SFML: Can't load music");
}