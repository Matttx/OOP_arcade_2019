/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Error.cpp
*/

#include "Error.hpp"

engine::util::Error::Error(
    const std::string& subject, const std::string& message)
{
    this->_what = subject + ": " + message;
}

engine::util::Error::~Error() = default;

const char* engine::util::Error::what() const noexcept
{
    return this->_what.c_str();
}