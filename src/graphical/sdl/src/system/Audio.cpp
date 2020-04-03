/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#include "Audio.hpp"

#include "../../../../engine/component/AAudio.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../component/Audio.hpp"

using namespace sdl;
using namespace system;

Audio::Audio(engine::ecs::World& world) : AAudio(world)
{
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
        if (SDL_GetAudioStatus() != SDL_AUDIO_PLAYING) {
            SDL_QueueAudio(sdlAudio.deviceId, sdlAudio.wavBuffer, sdlAudio.wavLength);
            SDL_PauseAudioDevice(sdlAudio.deviceId, 0);
        }
    }
}