/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_EMULATOR_SYSTEM_USER_HPP
#define OOP_ARCADE_2019_EMULATOR_SYSTEM_USER_HPP

#include "../../../engine/event/Input.hpp"
#include "../../../engine/system/AUser.hpp"

namespace game {

namespace emulator {

namespace system {

class User : public engine::system::AUser {
  public:
    explicit User(engine::ecs::World& world);
    ~User() override;

  public:
    void init() override;
    void update() override;
    void render() override;

  public:
    void inputHandler(engine::event::Input &input);
};

} // namespace system

} // namespace emulator

} // namespace game

#endif // OOP_ARCADE_2019_EMULATOR_SYSTEM_USER_HPP
