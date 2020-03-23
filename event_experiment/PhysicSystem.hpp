/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PhysicSystem
*/

#ifndef PHYSICSYSTEM_HPP_
#define PHYSICSYSTEM_HPP_

#include <iostream>
#include "CollisionEvent.hpp"

class PhysicSystem {
    public:
        void init() {
            std::cout << "Init du système physic" << std::endl;
        }
        void onCollisionEvent(CollisionEvent *collision) {
            std::cout << "Eh j'ai publish une collision" << std::endl;
        }
    protected:
    private:
};

#endif /* !PHYSICSYSTEM_HPP_ */
