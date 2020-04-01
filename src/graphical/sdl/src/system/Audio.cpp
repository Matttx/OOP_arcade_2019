/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#include <SDL2/SDL_ixer.h>

#include "Audio.hpp"

#include "../../../../engine/component/AAudio.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../component/Audio.hpp"

using namespace sdl;
using namespace system;

Audio::Audio(engine::ecs::World& world) : AAudio(world)
{
}

Audio::~Audio()
{
    Mix_CloseAudio();
}

void Audio::init()
{
}

void Audio::update()
{
}

void Audio::render()
{
    auto entities = getWorld().getEntities<engine::component::AAudio>();
    for (const auto& entity : entities) {
        auto& component = entity.get().getComponent<engine::component::AAudio>();
        auto& sdlAudio = dynamic_cast<sdl::component::Audio&>(component);
        if (Mix_PlayingMusic() != 1)
            Mix_PlayMusic(sdlAudio.music, 1)
    }
}