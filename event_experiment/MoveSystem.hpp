/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MoveSystem
*/

#ifndef MOVESYSTEM_HPP_
#define MOVESYSTEM_HPP_

#include <iostream>
#include "EventBus.hpp"
#include "CollisionEvent.hpp"
#include "CollisionEvent1.hpp"
#include "FunctionHandler.hpp"

class MoveSystem
{
public:
    void init(EventBus &eventBus)
    {
        std::cout << "MOVE :: Init du système move" << std::endl;
        eventBus.subscribe(this, &MoveSystem::onCollisionEvent);
        eventBus.subscribe(this, &MoveSystem::onCollisionEvent1);
    }

    void onCollisionEvent(CollisionEvent *collision)
    {
        std::cout << "MOVE :: Eh y'a eu une collision" << std::endl;
        (void)collision;
    }

    void onCollisionEvent1(CollisionEvent1 *collision)
    {
        std::cout << "MOVE :: Eh y'a eu une collision 1" << std::endl;
        (void)collision;
    }

protected:
private:
};

#endif /* !MOVESYSTEM_HPP_ */