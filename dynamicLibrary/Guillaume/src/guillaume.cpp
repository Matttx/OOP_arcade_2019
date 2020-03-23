/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** guillaume.cpp
*/

#include "guillaume.hpp"

#include <utility>


Guillaume::Guillaume(std::string  firstName, std::string  lastName, int age): _firstName(std::move(firstName)), _lastName(std::move(lastName)), _age(age) {

}

extern "C" Guillaume* create_object()
{
    return new Guillaume();
}

std::string Guillaume::getLastName() {
    return _lastName;
}

std::string Guillaume::getFirstName() {
    return _firstName;
}

int Guillaume::getAge() {
    return _age;
}