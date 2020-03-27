/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AAudio.cpp
*/

#include "AAudio.hpp"

engine::component::AAudio::AAudio(engine::ecs::Entity &entity, const std::vector<std::string> &paths): engine::ecs::AComponent(entity), _paths(paths) {
}
