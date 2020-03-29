/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AAI_HPP
#define OOP_ARCADE_2019_SYSTEM_AAI_HPP

#include "../ecs/ASystem.hpp"
#include "../ecs/World.hpp"

namespace engine {

namespace system {

class AAI : public ecs::ASystem {
  public:
    explicit AAI(ecs::World& world);
    ~AAI() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AAI_HPP
