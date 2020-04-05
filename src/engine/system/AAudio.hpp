/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP
#define OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP

#include "../ecs/ASystem.hpp"

namespace engine {

namespace system {
/**
 * @class AAudio that inherits from ASystem
 * 
 */
class AAudio : public ecs::ASystem {
  public:
    /**
     * @brief Construct a new AAudio object
     * 
     * @param world 
     */
    explicit AAudio(ecs::World& world);
    /**
     * @brief Destroy the AAudio object
     * 
     */
    ~AAudio() override = 0;
};

} // namespace system

} // namespace engine

#endif // OOP_ARCADE_2019_SYSTEM_AAUDIO_HPP
