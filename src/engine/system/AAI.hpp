/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AAI_HPP
#define OOP_ARCADE_2019_SYSTEM_AAI_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class AAI that inherits from ASystem
 * 
 */
class AAI : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new AAI object
     * 
     * @param world
     */
    explicit AAI(ecs::World& world);
    /**
     * @brief Destroy the AAI object
     * 
     */
    ~AAI() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AAI_HPP
