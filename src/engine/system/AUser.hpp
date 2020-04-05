/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AUser.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AUSER_HPP
#define OOP_ARCADE_2019_SYSTEM_AUSER_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class AUser that inherits from ASystem 
 * 
 */
class AUser : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new AUser object
     * 
     * @param world 
     */
    explicit AUser(ecs::World& world);
    /**
     * @brief Destroy the AUser object
     * 
     */
    ~AUser() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AUSER_HPP
