/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_ARENDER_HPP
#define OOP_ARCADE_2019_COMPONENT_ARENDER_HPP

#include <string>
#include <vector>

#include "../ecs/AComponent.hpp"
#include "../ecs/Entity.hpp"

namespace engine {

namespace component {

class ARender : public ecs::AComponent {
  public:
    std::vector<std::string> paths;

  public:
    ARender(ecs::Entity& entity, const std::vector<std::string>& paths);
    ~ARender() override = 0;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_ARENDER_HPP
