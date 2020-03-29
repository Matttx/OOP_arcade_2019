/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ISystem.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ISYSTEM_HPP
#define OOP_ARCADE_2019_ECS_ISYSTEM_HPP

#include "World.hpp"

namespace engine {

namespace ecs {

class ISystem {
  public:
    virtual ~ISystem() = 0;

  public:
    virtual World& getWorld() const = 0;

  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ISYSTEM_HPP
