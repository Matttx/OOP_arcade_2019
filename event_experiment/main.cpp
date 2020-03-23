/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include "Entity.hpp"
#include "Event.hpp"
#include "EventBus.hpp"
#include "AFunctionHandler.hpp"
#include "FunctionHandler.hpp"
#include "InputEvent.hpp"
#include "CollisionEvent.hpp"
#include "MovementSystem.hpp"

int main(void)
{
    Entity entityA;
    Entity entityB;
    EventBus eventBus;
    MovementSystem move;
    CollisionEvent collision(entityA, entityB);
    
    move.init(eventBus);
    //move.onCollisionEvent(&collision);

    (void)collision;
    return (0);
}
