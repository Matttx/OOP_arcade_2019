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

class MovementSystem {
    public:
        void init(EventBus& eventBus) {
            //FunctionHandler(this, MovementSystem::onCollisionEvent)
            eventBus.subscribe(this, this::&this.onCollisionEvent);
            std::cout << "Init du système movement" << std::endl;
        }

        void onCollisionEvent(CollisionEvent *collision) {
            std::cout << "Eh y'a eu une collision" << std::endl;
        }
    protected:
    private:
};

#endif /* !MOVEMENTSYSTEM_HPP_ */