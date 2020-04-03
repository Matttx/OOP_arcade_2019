/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** mock_component.hpp
*/

#ifndef OOP_ARCADE_2019_MOCK_COMPONENT_HPP
#define OOP_ARCADE_2019_MOCK_COMPONENT_HPP

  class Component : public engine::ecs::AComponent {
    public:
      Component(engine::ecs::Entity& entity): AComponent(entity) {};
      ~Component() override = default;
  };

#endif // OOP_ARCADE_2019_MOCK_COMPONENT_HPP
