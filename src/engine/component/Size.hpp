/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Size.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_SIZE_HPP
#define OOP_ARCADE_2019_COMPONENT_SIZE_HPP

#include "../ecs/AComponent.hpp"

namespace engine {

namespace component {

class Size : public ecs::AComponent {
  public:
    int width;
    int height;

  public:
    Size(ecs::Entity& entity, int width, int height);
    ~Size() override;
};

} // namespace component

} // namespace engine

#endif // OOP_ARCADE_2019_COMPONENT_SIZE_HPP
