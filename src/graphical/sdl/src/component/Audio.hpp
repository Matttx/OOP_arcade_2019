/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include <SDL2/SDL.h>

#include <string>
#include <vector>

#include "../../../../engine/component/AAudio.hpp"
#include "../../../../engine/ecs/Entity.hpp"

namespace sdl {

namespace component {

class Audio : public engine::component::AAudio {
  public:
    Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
    ~Audio() override;
    SDL_AudioSpec wavSpec;
    Uint32 wavLength;
    Uint8* wavBuffer;
    SDL_AudioDeviceID deviceId;

  private:
};

} // Namespace component
} // Namespace sdl
#endif /* !AUDIO_HPP_ */
