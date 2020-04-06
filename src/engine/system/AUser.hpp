/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.hpp
*/

/**
 * @file AUser.hpp
 * @brief Class for user system implementation
 */

#ifndef OOP_ARCADE_2019_SYSTEM_AUSER_HPP
#define OOP_ARCADE_2019_SYSTEM_AUSER_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Abstract class of user system
 *
 */
class AUser : public ecs::ASystem {
  public:
    /**
     * @brief Constructor of AUser
     *
     * @param world World that the system belongs to
     */
    explicit AUser(ecs::World& world);
    /**
     * @brief Destructor of AUser
     *
     */
    ~AUser() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AUSER_HPP
