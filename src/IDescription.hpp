/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IGraphical.hpp
*/

#ifndef OOP_ARCADE_2019_IGRAPHICAL_HPP
#define OOP_ARCADE_2019_IGRAPHICAL_HPP

#include <string>
class IDescription {
public:
    virtual std::string getLastName() = 0;
    virtual std::string getFirstName() = 0;
    virtual int getAge() = 0;
    virtual ~IDescription() = 0;
};

using DesCreator = IDescription* (*)();

#endif // OOP_ARCADE_2019_IGRAPHICAL_HPP
