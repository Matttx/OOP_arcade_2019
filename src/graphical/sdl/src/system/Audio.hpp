/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Audio
*/

#ifndef SYSTEM_AUDIO_HPP_
#define SYSTEM_AUDIO_HPP_

#include "../../../../engine/system/AAudio.hpp"

namespace sdl {
namespace system {
/**
 * @class Audio that inherits from AAudio
 * 
 */
class Audio : public engine::system::AAudio {
  public:
    /**
     * @brief Construct a new Audio object
     * 
     * @param world : the world of the entity
     */
    explicit Audio(engine::ecs::World& world);
    /**
     * @brief Destroy the Audio object
     * 
     */
    ~Audio() override = default;

    /**
     * @brief init ; init the system Audio
     * 
     */
    void init() override;
    /**
     * @brief update : update the system Audio
     * 
     */
    void update() override;
    /**
     * @brief render : render the system Audio
     * 
     */
    void render() override;
};

} // Namespace system
} // Namespace sdl

#endif /* !AUDIO_HPP_ */
