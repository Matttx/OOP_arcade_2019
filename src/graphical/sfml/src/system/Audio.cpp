/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio.cpp
*/

#include "Audio.hpp"

#include <AAudio.hpp>

#include "../component/Audio.hpp"

sfml::system::Audio::Audio(engine::ecs::World& world) : AAudio(world)
{
}

void sfml::system::Audio::init()
{
}

void sfml::system::Audio::update()
{
}

void sfml::system::Audio::render()
{
    auto entities = getWorld().getEntities<engine::component::AAudio>();
    for (const auto& entity : entities) {
        auto& component =
            entity.get().getComponent<engine::component::AAudio>();
        auto& sfmlAudio = dynamic_cast<sfml::component::Audio&>(component);
        if (sfmlAudio.music.getStatus() != sf::Music::Status::Playing)
            sfmlAudio.music.play();
    }
}