/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAnimations.hpp
*/

/**
 * @file AAnimations.hpp
 * @brief Class for animations system implementation
 */

#ifndef OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP
#define OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Abstract class of animations system
 *
 */
class AAnimations : public ecs::ASystem {
  public:
    /**
     * @brief Constructor of AAnimations
     *
     * @param world World that the system belongs to
     */
    explicit AAnimations(ecs::World& world);
    /**
     * @brief Destructor of AAnimations
     *
     */
    ~AAnimations() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP
