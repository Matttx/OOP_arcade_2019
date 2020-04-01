/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGame.cpp
*/

#include "AGame.hpp"

game::AGame::AGame(const std::string& name) : _name(name)
{
}

game::AGame::~AGame() = default;

std::string game::AGame::getName()
{
    return this->_name;
}
