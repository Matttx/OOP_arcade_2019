/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Collision.hpp
*/

#ifndef OOP_ARCADE_2019_EVENT_COLLISION_HPP
#define OOP_ARCADE_2019_EVENT_COLLISION_HPP

#include "../ecs/Entity.hpp"
#include "../eventbus/AEvent.hpp"

namespace engine {

namespace event {

class Collision : public eventbus::AEvent {
  public:
    ecs::Entity &entity1;
    ecs::Entity &entity2;

  public:
    Collision(ecs::Entity& entity1, ecs::Entity& entity2);
    ~Collision() override;
};

}

}

#endif // OOP_ARCADE_2019_EVENT_COLLISION_HPP
