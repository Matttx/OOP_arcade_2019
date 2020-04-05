/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI.hpp
*/

#ifndef OOP_ARCADE_2019_COMPONENT_AI_HPP
#define OOP_ARCADE_2019_COMPONENT_AI_HPP

#include "../../../../engine/component/AAI.hpp"
#include "../../../../engine/ecs/Entity.hpp"

namespace pacman {
namespace component {
class AI : public engine::component::AAI {
  public:
    explicit AI(engine::ecs::Entity& entity);
    ~AI() override = default;

  public:
    int startPosX;
    int startPosY;
    bool isAlive;
    bool scared;
};
}
}

#endif // OOP_ARCADE_2019_AI_HPP
