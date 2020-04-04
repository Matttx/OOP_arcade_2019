/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** System.cpp
*/

#include "System.hpp"

template<>
void engine::save::system::AAudio::addToWorld()
{
    std::apply(
        [this]() {
            this->_world.template addSystem<engine::system::AAudio>();
        },
        _args);
}

template<>
void engine::save::system::ARender::addToWorld()
{
    std::apply(
        [this]() {
            this->_world.template addSystem<engine::system::ARender>();
        },
        _args);
}