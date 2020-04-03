/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "../../../../engine/component/AAudio.hpp"
#include "../../../../engine/ecs/Entity.hpp"
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

namespace sdl {

namespace component {

class Audio : public engine::component::AAudio {
    public:
        Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
        ~Audio() override;
        Mix_Music *music;
    protected:
    private:
};

} // Namespace component
} // Namespace sdl
#endif /* !AUDIO_HPP_ */