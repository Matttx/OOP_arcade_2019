/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAnimations.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP
#define OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class AAnimation that inherits from ASystem
 * 
 */
class AAnimations : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new AAnimations object
     * 
     * @param world 
     */
    explicit AAnimations(ecs::World& world);
    /**
     * @brief Destroy the AAnimations object
     * 
     */
    ~AAnimations() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AANIMATIONS_HPP
