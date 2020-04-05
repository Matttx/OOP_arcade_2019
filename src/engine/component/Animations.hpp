/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Animations.hpp
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
 * @class Class of component Animation
 * 
 */
class Animations : public ecs::AComponent {
  public:
    /**
     * @brief list : map of animation. Its first key is a string that represents the name of the animation. The second is the animation type
     * 
     */
    const std::map<std::string, type::Animation> list;
    /**
     * @brief currentAnimation : the name of the current animation
     * 
     */
    std::string currentAnimation;
    /**
     * @brief currentFrame : the current frame of the animation
     * 
     */
    int currentFrame;

  public:
    /**
     * @brief Construct a new Animations object
     * 
     * @param entity : the entity that the component belongs to
     * @param list : a list of animation 
     */
    Animations(ecs::Entity& entity,
        const std::map<std::string, type::Animation>& list);
    /**
     * @brief Destroy the Animations object
     * 
     */
    ~Animations() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_ANIMATIONS_HPP
