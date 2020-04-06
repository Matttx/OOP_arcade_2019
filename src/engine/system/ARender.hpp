/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

/**
 * @file ARender.hpp
 * @brief Class for render system implementation
 */

#ifndef OOP_ARCADE_2019_SYSTEM_ARENDER_HPP
#define OOP_ARCADE_2019_SYSTEM_ARENDER_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Abstract class of render system
 *
 */
class ARender : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new ARender object
     *
     * @param world World that the system belongs to
     */
    explicit ARender(ecs::World& world);
    /**
     * @brief Destroy the ARender object
     *
     */
    ~ARender() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_ARENDER_HPP
