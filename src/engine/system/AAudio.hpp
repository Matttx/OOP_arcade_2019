/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP
#define OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP

#include "../ecs/ASystem.hpp"
#include "../ecs/World.hpp"

namespace engine {

namespace system {

class AAudio : public ecs::ASystem {
  public:
    explicit AAudio(ecs::World& world);
    ~AAudio() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP
