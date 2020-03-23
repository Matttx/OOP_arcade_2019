/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** thomas.cpp
*/

#include "thomas.hpp"

Thomas::Thomas(std::string  firstName, std::string  lastName, int age): _firstName(std::move(firstName)), _lastName(std::move(lastName)), _age(age) {

}

extern "C" Thomas* create_object()
{
    return new Thomas();
}

std::string Thomas::getLastName() {
    return _lastName;
}

std::string Thomas::getFirstName() {
    return _firstName;
}

int Thomas::getAge() {
    return _age;
}
