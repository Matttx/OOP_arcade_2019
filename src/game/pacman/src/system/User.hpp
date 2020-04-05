/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** User.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_USER_HPP
#define OOP_ARCADE_2019_SYSTEM_USER_HPP

#include "../../../../engine/component/Hitbox.hpp"
#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../../../../engine/event/Input.hpp"
#include "../../../../engine/system/AUser.hpp"
#include "../Game.hpp"

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
    bool isCollide(const engine::component::Transform& transform1, const engine::component::Hitbox& hitbox1,
                    const engine::component::Transform& transform2, const engine::component::Hitbox& hitbox2);
    void inputHandler(engine::event::Input& input);
};
}
}

#endif // OOP_ARCADE_2019_USER_HPP
