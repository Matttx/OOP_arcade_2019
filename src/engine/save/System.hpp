/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** System.hpp
*/

/**
 * @file System.hpp
 * @brief System parameters saver
 */

#ifndef OOP_ARCADE_2019_SAVE_SYSTEM_HPP
#define OOP_ARCADE_2019_SAVE_SYSTEM_HPP

#include <functional>
#include <tuple>

#include "../ecs/World.hpp"

namespace engine {

namespace save {

/**
 * @brief Class of system saver
 *
 * @tparam T Type of system
 * @tparam TArgs Type of system parameters
 */
template<typename T, typename... TArgs>
class System {
  public:
    /**
 * @brief Constructor of System
 *
 * @param entity World that the system belongs to
 * @param args System parameters
 */
    explicit System(ecs::World &world, TArgs... args) : _world(world), _args(args...)
    {
    }

    /**
     * @brief Destructor of System
     */
    ~System() = default;

  public:
    /**
     * @brief Add the system to the world
     */
    void addToWorld()
    {
        std::apply(
            [this](auto... args) {
                this->_world.template addSystem<T>(args...);
            },
            _args);
    }

    /**
     * @brief Remove the system from the world
     */
    void removeFromWorld()
    {
        _world.removeSystem<T>();
    }

  private:
    /**
     * @brief Reference of the world
     */
    ecs::World &_world;
    /**
     * @brief System parameters
     */
    std::tuple<TArgs...> _args;
};

namespace system {

/**
 * @brief AAnimations system saver signature
 */
using AAnimations = System<engine::system::AAnimations>;
/**
 * @brief AAudio system saver signature
 */
using AAudio = System<engine::system::AAudio>;
/**
 * @brief ARender system saver signature
 */
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
