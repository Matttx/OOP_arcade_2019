/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AFunctionHandler
*/

#include <iostream>
#include "AFunctionHandler.hpp"

void AFunctionHandler::exec(Event* event) {
    call(event);
    std::cout << "Call de l'event" << std::endl;
}