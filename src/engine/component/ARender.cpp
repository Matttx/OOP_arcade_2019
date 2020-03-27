/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ARender.cpp
*/

#include "ARender.hpp"

engine::component::ARender::ARender(engine::ecs::Entity &entity, const std::vector<std::string> &paths): engine::ecs::AComponent(entity), _paths(paths) {

}
