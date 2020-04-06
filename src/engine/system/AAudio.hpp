/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

/**
 * @brief Class for audio system implementation
 */

#ifndef OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP
#define OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class Abstract class of audio system
 *
 */
class AAudio : public ecs::ASystem {
  public:
    /**
     * @brief Constructor of AAudio
     *
     * @param world World that the system belongs to
     */
    explicit AAudio(ecs::World& world);
    /**
     * @brief Destructor of AAudio
     *
     */
    ~AAudio() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP
