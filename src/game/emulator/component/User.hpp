/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_SRC_GAME_EMULATOR_COMPONENT_USER_HPP
#define OOP_ARCADE_2019_SRC_GAME_EMULATOR_COMPONENT_USER_HPP

#include "../../../engine/component/AUser.hpp"

namespace emulator {

namespace component {

class User : public engine::component::AUser {
  public:
    enum USERSTEP { GRAPHICAL, GAME };

  public:
    explicit User(engine::ecs::Entity& entity);
    ~User() override;

  public:
    enum USERSTEP step = GRAPHICAL;
    int index = 0;
};

} // namespace component

} // namespace emulator

#endif // OOP_ARCADE_2019_SRC_GAME_EMULATOR_COMPONENT_USER_HPP
