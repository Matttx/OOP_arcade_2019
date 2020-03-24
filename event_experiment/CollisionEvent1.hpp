/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CollisionEvent
*/

#ifndef COLLISIONEVENT1_HPP_
#define COLLISIONEVENT1_HPP_

#include "Event.hpp"
#include "Entity.hpp"

class CollisionEvent1 : public Event {
    public:
        CollisionEvent1(Entity a, Entity b): entityA(a), entityB(b) {};
        void print2() {
            std::cout << "Print collision 2" << std::endl;
        };
        Entity entityA;
        Entity entityB;
    protected:
    private:
};

#endif /* !COLLISIONEVENT_HPP_ */
