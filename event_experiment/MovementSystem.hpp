/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MovementSystem
*/

#ifndef MOVEMENTSYSTEM_HPP_
#define MOVEMENTSYSTEM_HPP_

#include <iostream>
#include "EventBus.hpp"
#include "CollisionEvent.hpp"
#include "FunctionHandler.hpp"

class MovementSystem
{
public:
    void init(EventBus &eventBus)
    {
        std::cout << "MOVEMENT :: Init du système movement" << std::endl;
        eventBus.subscribe(this, &MovementSystem::onCollisionEvent);
    }

    void onCollisionEvent(CollisionEvent *collision)
    {
        std::cout << "MOVEMENT :: Eh y'a eu une collision" << std::endl;
        (void)collision;
    }

protected:
private:
};

#endif /* !MOVEMENTSYSTEM_HPP_ */