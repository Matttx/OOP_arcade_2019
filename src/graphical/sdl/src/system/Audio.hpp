/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#ifndef AUDIO_HPP_
#define AUDIO_HPP_

#include "../../../../engine/system/AAudio.hpp"

namespace sdl {
namespace system {

class Audio : engine::system::AAudio {
    public:
        Audio(engine::ecs::World& world);
        ~Audio();
        void init() override;
        void update() override;
        void render() override;

};

} // Namespace system
} // Namespace sdl

#endif /* !AUDIO_HPP_ */
