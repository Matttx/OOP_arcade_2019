/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations
*/

#ifndef ANIMATION_HPP_
#define ANIMATION_HPP_

#include "../../../../engine/system/AAnimations.hpp"
#include "../../../../engine/type/Animation.hpp"

namespace sdl {
namespace system {
/**
 * @class Animations that inherits from AAnimations
 * 
 */
class Animations : public engine::system::AAnimations {
  public:
    /**
     * @brief Construct a new Animations object
     * 
     * @param world : the world of the entity
     */
    Animations(engine::ecs::World& world);
    /**
     * @brief Destroy the Animations object
     * 
     */
    ~Animations() override = default;

    /**
     * @brief init : init the animation system
     * 
     */
    void init() override;
    /**
     * @brief update : update the animation system
     * 
     */
    void update() override;
    /**
     * @brief render : render the animation system
     * 
     */
    void render() override;
};

} // Namespace system
} // Namespace sdl

#endif /* !ANIMATION_HPP_ */
