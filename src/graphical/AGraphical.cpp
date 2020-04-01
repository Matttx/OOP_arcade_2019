/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AGraphical.cpp
*/

#include "AGraphical.hpp"

graphical::AGraphical::AGraphical(
    const std::string& name, LIBTYPE type, engine::eventbus::EventBus& eventBus)
    : _name(name), _type(type), _eventBus(eventBus)
{
}

graphical::AGraphical::~AGraphical() = default;

std::string graphical::AGraphical::getName() const
{
    return this->_name;
}

LIBTYPE graphical::AGraphical::getType() const
{
    return this->_type;
}
