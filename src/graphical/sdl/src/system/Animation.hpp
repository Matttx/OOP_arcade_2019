/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animation
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/type/Animation.hpp"

namespace sdl {
namespace system {

class Animation : public engine::system::AAnimations {
    public:
        Animation(engine::ecs::World& world);
        ~Animation() override = default;

        void init() override;
        void update() override;
        void render() override;
};

} // Namespace system
} // Namespace sdl

#endif /* !ANIMATION_HPP_ */
