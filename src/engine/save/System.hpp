/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** System.hpp
*/

#ifndef OOP_ARCADE_2019_SAVE_SYSTEM_HPP
#define OOP_ARCADE_2019_SAVE_SYSTEM_HPP

#include <functional>
#include <tuple>

#include "../ecs/World.hpp"

namespace engine {

namespace save {

template<typename T, typename... TArgs>
class System {
  public:
    explicit System(ecs::World &world, TArgs... args) : _world(world), _args(args...)
    {
    }

    ~System() = default;

  public:
    void addToWorld()
    {
        std::apply(
            [this](auto... args) {
                this->_world.template addSystem<T>(args...);
            },
            _args);
    }

    void removeFromWorld()
    {
        _world.removeSystem<T>();
    }

  private:
    ecs::World &_world;
    std::tuple<TArgs...> _args;
};

namespace system {

using AAnimations = System<engine::system::AAnimations>;
using AAudio = System<engine::system::AAudio>;
using ARender = System<engine::system::ARender>;

} // namespace system

template<>
void system::AAnimations::addToWorld();

template<>
void system::AAudio::addToWorld();

template<>
void system::ARender::addToWorld();

} // namespace save

} // namespace engine

#endif // OOP_ARCADE_2019_SAVE_SYSTEM_HPP
