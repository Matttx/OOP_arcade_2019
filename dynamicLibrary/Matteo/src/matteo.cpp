/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** matteo.cpp
*/

#include "matteo.hpp"

#include <utility>

Matteo::Matteo(std::string  firstName, std::string  lastName, int age): _firstName(std::move(firstName)), _lastName(std::move(lastName)), _age(age) {

}

extern "C" Matteo* create_object()
{
    return new Matteo();
}

std::string Matteo::getLastName() {
    return _lastName;
}

std::string Matteo::getFirstName()  {
    return _firstName;
}

int Matteo::getAge() {
    return _age;
}
