/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Component.cpp
*/

#include "Component.hpp"

template<>
void engine::save::component::AAudio::addToEntity()
{
    std::apply(
        [this](const std::vector<std::string>& paths) {
            this->_entity.template addComponent<engine::component::AAudio>(
                paths);
        },
        _args);
}

template<>
void engine::save::component::ARender::addToEntity()
{
    std::apply(
        [this](const std::vector<std::string>& paths) {
            this->_entity.template addComponent<engine::component::ARender>(
                paths);
        },
        _args);
}