/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#ifndef SYSTEM_AUDIO_HPP_
#define SYSTEM_AUDIO_HPP_

#include "../../../../engine/system/AAudio.hpp"

namespace sdl {
namespace system {

class Audio : public engine::system::AAudio {
    public:
        explicit Audio(engine::ecs::World& world);
        ~Audio() override = default;
        void init() override;
        void update() override;
        void render() override;
};

} // Namespace system
} // Namespace sdl

#endif /* !AUDIO_HPP_ */
