/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/type/Animation.hpp"

namespace sdl {
namespace system {

class Animations : public engine::system::AAnimations {
  public:
    Animations(engine::ecs::World& world);
    ~Animations() override = default;

    void init() override;
    void update() override;
    void render() override;
};

} // Namespace system
} // Namespace sdl

#endif /* !ANIMATION_HPP_ */
