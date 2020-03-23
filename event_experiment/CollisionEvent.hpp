/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CollisionEvent
*/

#ifndef COLLISIONEVENT_HPP_
#define COLLISIONEVENT_HPP_

#include "Event.hpp"
#include "Entity.hpp"

class CollisionEvent : public Event {
    public:
        CollisionEvent(Entity a, Entity b): entityA(a), entityB(b) {};
        Entity entityA;
        Entity entityB;
    protected:
    private:
};

#endif /* !COLLISIONEVENT_HPP_ */
