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
#include "../ecs/Entity.hpp"
#include "../type/Animation.hpp"

namespace engine {

namespace component {

class Animations : public ecs::AComponent {
  public:
    const std::map<std::string, type::Animation> list;

  public:
    Animations(ecs::Entity& entity,
        const std::map<std::string, type::Animation>& list);
    ~Animations() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_ANIMATIONS_HPP
