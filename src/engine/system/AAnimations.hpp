/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAnimations.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP
#define OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {

class AAnimations : public ecs::ASystem {
  public:
    explicit AAnimations(ecs::World& world);
    ~AAnimations() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP
