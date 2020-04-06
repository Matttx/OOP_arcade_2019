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
/**
 * @class ISystem
 *
 */
class ISystem {
  public:
    /**
     * @brief Destroy the ISystem object
     *
     */
    virtual ~ISystem() = 0;

  public:
    /**
     * @brief Get the World object : function that permite child to get a world
     *
     * @return World& : return a reference to a World
     */
    virtual World& getWorld() const = 0;

  public:
    /**
     * @brief init : pure virtual function for child class in order to init the system
     *
     */
    virtual void init() = 0;
    /**
     * @brief update : pure virtual function for child class in order to update the system
     *
     */
    virtual void update() = 0;
    /**
     * @brief render : pure virtual function for child class in order to render the system
     *
     */
    virtual void render() = 0;
};

} // namespace ecs

} // namespace engine

#endif // OOP_ARCADE_2019_ECS_ISYSTEM_HPP
