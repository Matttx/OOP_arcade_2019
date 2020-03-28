/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Input.cpp
*/

#include "Input.hpp"

engine::event::Input::Input(engine::event::Input::KEYCODE code) : code(code)
{
}

engine::event::Input::~Input() = default;
