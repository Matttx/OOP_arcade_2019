/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_USER_HPP
#define OOP_ARCADE_2019_SYSTEM_USER_HPP

#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../../../../engine/system/AUser.hpp"
namespace pacman {
namespace system {
class User : public engine::system::AUser {
  public:
    User(engine::ecs::World& world);
    ~User() override = default;
    void init() override;
    void update() override;
    void render() override;
    void collisionHandler(engine::event::Collision &collision);
    static std::vector<bool> isCollide(const engine::component::Motion& motion);
};
}
}

#endif // OOP_ARCADE_2019_USER_HPP
