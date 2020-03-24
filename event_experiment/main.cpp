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
#include "CollisionEvent1.hpp"
#include "MovementSystem.hpp"
#include "MouvementSystem.hpp"
#include "MoveSystem.hpp"
#include "PhysicSystem.hpp"

int main(void)
{
    Entity entityA;
    Entity entityB;
    EventBus eventBus;
    MovementSystem movement;
    MouvementSystem mouve;
    MoveSystem move;
    PhysicSystem physic;
    CollisionEvent collision(entityA, entityB);
    CollisionEvent1 collision1(entityA, entityB);
    
    movement.init(eventBus);
    mouve.init(eventBus);
    move.init(eventBus);
    physic.detectCollision(&collision, eventBus);

    (void)collision;
    return (0);
}
