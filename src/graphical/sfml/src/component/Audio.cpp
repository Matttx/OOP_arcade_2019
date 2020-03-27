/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio.cpp
*/

#include "Audio.hpp"

sfml::component::Audio::Audio(
    engine::ecs::Entity& entity, std::vector<std::string>& paths)
    : engine::component::AAudio(entity, paths)
{
}

sfml::component::Audio::~Audio()
{
}