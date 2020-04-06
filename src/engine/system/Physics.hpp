/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Physics.hpp
*/

/**
 * @file Physics.hpp
 * @brief Physics system
 */

#ifndef OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP
#define OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Class of physics system
 *
 */
class Physics : public ecs::ASystem {
  public:
    /**
     * @brief Constructor of Physics
     *
     * @param world World that the system belongs to
     */
    explicit Physics(ecs::World& world);
    /**
     * @brief Destructor of Physics
     *
     */
    ~Physics() override;

  public:
    /**
     * @brief init : Initialize the physics system
     *
     */
    void init() override;
    /**
     * @brief update : Update the physics system
     *
     */
    void update() override;
    /**
     * @brief render : Render the physics system
     *
     */
    void render() override;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_PHYSICS_HPP
