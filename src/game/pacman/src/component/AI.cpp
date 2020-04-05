/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AI.cpp
*/

#include "AI.hpp"
pacman::component::AI::AI(engine::ecs::Entity& entity) : engine::component::AAI(entity)
{
    this->startPosX = 0;
    this->startPosY = 0;
    this->isAlive = false;
    this->scared = false;
}
