/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_USER_HPP
#define OOP_ARCADE_2019_COMPONENT_USER_HPP

#include "../../../../engine/component/AUser.hpp"
#include "../../../../engine/ecs/Entity.hpp"

namespace pacman {
namespace component {
class User : public engine::component::AUser {
  public:
    explicit User(engine::ecs::Entity& entity);
    ~User() override = default;

  public:
    int eat;
    bool supaSayajin;
    bool isAlive;
};
}
}

#endif // OOP_ARCADE_2019_USER_HPP
