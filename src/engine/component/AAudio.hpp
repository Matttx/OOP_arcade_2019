/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP
#define OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"
#include "../ecs/Entity.hpp"

namespace engine {

namespace component {

class AAudio : public ecs::AComponent {
  public:
    const std::vector<std::string> paths;

  public:
    AAudio(ecs::Entity& entity, const std::vector<std::string>& paths);
    ~AAudio() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_AAUDIO_HPP
