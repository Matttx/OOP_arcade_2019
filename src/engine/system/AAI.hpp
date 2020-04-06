/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAI.hpp
*/

/**
 * @brief Class for AI system implementation
 */

#ifndef OOP_ARCADE_2019_SYSTEM_AAI_HPP
#define OOP_ARCADE_2019_SYSTEM_AAI_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Abstract class of AI system
 *
 */
class AAI : public ecs::ASystem {
  public:
    /**
     * @brief Constructor of AAI
     *
     * @param world World that the system belongs to
     */
    explicit AAI(ecs::World& world);
    /**
     * @brief Destructor of AAI
     *
     */
    ~AAI() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AAI_HPP
