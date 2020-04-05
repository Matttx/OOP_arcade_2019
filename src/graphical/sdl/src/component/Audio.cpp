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
    SDL_LoadWAV(
        paths[LIBTYPE::GRAPHIC].c_str(), &wavSpec, &wavBuffer, &wavLength);
    deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
}

Audio::~Audio()
{
    SDL_CloseAudioDevice(deviceId);
    SDL_FreeWAV(wavBuffer);
}