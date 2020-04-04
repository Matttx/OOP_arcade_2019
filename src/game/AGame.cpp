/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

game::AGame::AGame(const std::string& name, engine::ecs::Universe& universe) : _name(name), _universe(universe)
{
}

game::AGame::~AGame() = default;

std::string game::AGame::getName() const
{
    return this->_name;
}

engine::ecs::Universe& game::AGame::getUniverse() const
{
    return this->_universe;
}
