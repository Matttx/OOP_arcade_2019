/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ASystem.hpp
*/

#ifndef OOP_ARCADE_2019_ECS_ASYSTEM_HPP
#define OOP_ARCADE_2019_ECS_ASYSTEM_HPP

namespace engine {
namespace ecs {
class World;
} // namespace ecs
} // namespace engine

#include "World.hpp"

namespace engine {

namespace ecs {

class ASystem {
  public:
    explicit ASystem(World& world);
    virtual ~ASystem() = 0;

  public:
    World& getWorld() const;

  public:
    virtual void init() = 0;
    virtual void update() = 0;
    virtual void render() = 0;

  private:
    World& _world;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ASYSTEM_HPP
