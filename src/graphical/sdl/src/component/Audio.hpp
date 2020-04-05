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
/**
 * @class Audio
 * 
 */
class Audio : public engine::component::AAudio {
    public:
        /**
         * @brief Construct a new Audio object
         * 
         * @param entity : the entity of the component
         * @param paths : a vector path to an audio device
         */
        Audio(engine::ecs::Entity& entity, const std::vector<std::string>& paths);
        /**
         * @brief Destroy the Audio object
         * 
         */
        ~Audio() override;
        /**
         * @brief SDL_AudioSpec : 
         * 
         */
        SDL_AudioSpec wavSpec;
        /**
         * @brief wavLength : length of audio file
         * 
         */
        Uint32 wavLength;
        /**
         * @brief wavBuffer : buffer or wav
         * 
         */
        Uint8 *wavBuffer;
        /**
         * @brief deviceId : Id of the audio device
         * 
         */
        SDL_AudioDeviceID deviceId;
    private:
};

} // Namespace component
} // Namespace sdl
#endif /* !AUDIO_HPP_ */
