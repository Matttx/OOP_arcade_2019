/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_EMULATOR_COMPONENT_USER_HPP
#define OOP_ARCADE_2019_EMULATOR_COMPONENT_USER_HPP

#include "../../../engine/component/AUser.hpp"

namespace game {

namespace emulator {

namespace component {

class User : public engine::component::AUser {
  public:
    enum USERSTEP { CHOOSE_GAME, CHOOSE_GRAPHICAL };

  public:
    explicit User(engine::ecs::Entity& entity);
    ~User() override;

  public:
    enum USERSTEP step = CHOOSE_GAME;
    int buttonIndex = 0;
};

} // namespace component

} // namespace emulator

} // namespace game

#endif // OOP_ARCADE_2019_EMULATOR_COMPONENT_USER_HPP
