/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI.hpp
*/

#ifndef OOP_ARCADE_2019_SYSTEM_AI_HPP
#define OOP_ARCADE_2019_SYSTEM_AI_HPP

#include "../../../../engine/component/Motion.hpp"
#include "../../../../engine/component/Transform.hpp"
#include "../../../../engine/ecs/World.hpp"
#include "../../../../engine/event/Collision.hpp"
#include "../../../../engine/system/AAI.hpp"
#include "../Game.hpp"

namespace pacman {
namespace system {
class AI : public engine::system::AAI {
  public:
    explicit AI(engine::ecs::World& world);
    ~AI() override = default;
    void init() override;
    void update() override;
    void render() override;
    void collisionHandler(engine::event::Collision &collision);
    static std::vector<bool> isCollide(const engine::component::Motion& motion);
};
}
}


#endif // OOP_ARCADE_2019_AI_HPP
