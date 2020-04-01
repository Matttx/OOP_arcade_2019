/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Physics.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP
#define OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP

#include "../ecs/ASystem.hpp"
#include "../ecs/World.hpp"

namespace engine {

namespace system {

class Physics : public ecs::ASystem {
  public:
    explicit Physics(ecs::World& world);
    ~Physics() override;

  public:
    void init() override;
    void update() override;
    void render() override;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP
