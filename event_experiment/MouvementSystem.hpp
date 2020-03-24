/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MouvementSystem
*/

#ifndef MOUVEMENTSYSTEM_HPP_
#define MOUVEMENTSYSTEM_HPP_

#include <iostream>
#include "EventBus.hpp"
#include "CollisionEvent1.hpp"
#include "FunctionHandler.hpp"

class MouvementSystem
{
public:
    void init(EventBus &eventBus)
    {
        std::cout << "MOUVEMENT :: Init du système mouvement" << std::endl;
        eventBus.subscribe(this, &MouvementSystem::onCollisionEvent1);
    }

    void onCollisionEvent1(CollisionEvent1 *collision)
    {
        std::cout << "MOUVEMENT :: Eh y'a eu une collision 1" << std::endl;
        (void)collision;
    }

protected:
private:
};

#endif /* !MOVEMENTSYSTEM_HPP_ */