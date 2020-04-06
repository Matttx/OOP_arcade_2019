/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Movement.hpp
*/

/**
 * @file Movement.hpp
 * @brief Movement system
 */

#ifndef OOP_ARCADE_2019_SYSTEM_MOVEMENT_HPP
#define OOP_ARCADE_2019_SYSTEM_MOVEMENT_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Class of movement system
 *
 */
class Movement : public ecs::ASystem {
  public:
    /**
     * @brief Constructor of Movement
     *
     * @param world World that the system belongs to
     */
    explicit Movement(ecs::World& world);
    /**
     * @brief Destructor of Movement
     *
     */
    ~Movement() override;

  public:
    /**
     * @brief init : Initialize the movement system
     *
     */
    void init() override;
    /**
     * @brief update : Update the movement system
     *
     */
    void update() override;
    /**
     * @brief render : Render the movement system
     *
     */
    void render() override;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_MOVEMENT_HPP
