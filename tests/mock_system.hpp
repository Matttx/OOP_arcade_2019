/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** mock_system.hpp
*/

#ifndef OOP_ARCADE_2019_MOCK_SYSTEM_HPP
#define OOP_ARCADE_2019_MOCK_SYSTEM_HPP

#include "../src/engine/ecs/World.hpp"

class System : public engine::ecs::ASystem {
    public:
      explicit System(engine::ecs::World& world): ASystem(world) {};
      ~System() override = default;
      void init() override {};
      void update() override {};
      void render() override {};
};

#endif // OOP_ARCADE_2019_MOCK_SYSTEM_HPP
