/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.hpp
*/

/**
 * @file Animations.hpp
 * @brief Animations component
 */

#ifndef OOP_ARCADE_2019_COMPONENT_ANIMATIONS_HPP
#define OOP_ARCADE_2019_COMPONENT_ANIMATIONS_HPP

#include <map>
#include <string>

#include "../ecs/AComponent.hpp"
#include "../type/Animation.hpp"

namespace engine {

namespace component {
/**
 * @class Class of animation component
 *
 */
class Animations : public ecs::AComponent {
  public:
    /**
     * @brief list : Map of animations.
     * Key: Name of the animation
     * Value: Animation definition
     *
     */
    const std::map<std::string, type::Animation> list;
    /**
     * @brief currentAnimation : Name of the current animation
     *
     */
    std::string currentAnimation;
    /**
     * @brief currentFrame : Current frame of the animation
     *
     */
    int currentFrame {};
    /**
     * @brief lastTimeMs : Time in miliseconds
     *
     */
    unsigned int lastTimeMs {};

  public:
    /**
     * @brief Constructor of Animations
     *
     * @param entity : Entity that the component belongs to
     * @param list : List of animation
     */
    Animations(ecs::Entity& entity, const std::map<std::string, type::Animation>& list);
    /**
     * @brief Destructor of Annimations
     *
     */
    ~Animations() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_ANIMATIONS_HPP
