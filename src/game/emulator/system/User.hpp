/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_SRC_GAME_EMULATOR_SYSTEM_USER_HPP
#define OOP_ARCADE_2019_SRC_GAME_EMULATOR_SYSTEM_USER_HPP

#include "../../../engine/event/Input.hpp"
#include "../../../engine/system/AUser.hpp"
#include "../component/User.hpp"

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
    void updateUserGame();
    void updateUserGraphical();
    void inputManager(engine::event::Input& input);
    void inputManagerGame(
        engine::event::Input& input, emulator::component::User& user);
    void inputManagerGraphical(
        engine::event::Input& input, emulator::component::User& user);
};

} // namespace system

} // namespace emulator

#endif // OOP_ARCADE_2019_SRC_GAME_EMULATOR_SYSTEM_USER_HPP
