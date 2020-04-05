/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#include "Audio.hpp"

#include "../../../IGraphical.hpp"

using namespace sdl;
using namespace component;

Audio::Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths)
    : engine::component::AAudio(entity, paths)
{
    if (!SDL_LoadWAV(
            paths[LIBTYPE::GRAPHIC].c_str(), &wavSpec, &wavBuffer, &wavLength))
        throw std::runtime_error(
            std::string("SDL: Can't load music: ", SDL_GetError()).c_str());

    deviceId = SDL_OpenAudioDevice(nullptr, 0, &wavSpec, nullptr, 0);

    if (!deviceId)
        throw std::runtime_error(
            std::string("SDL: Can't open audio device: ", SDL_GetError())
                .c_str());
}

Audio::~Audio()
{
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}