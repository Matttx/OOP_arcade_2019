/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** thomas.hpp
*/

#ifndef OOP_ARCADE_2019_THOMAS_HPP
#define OOP_ARCADE_2019_THOMAS_HPP

#include "../../../src/IDescription.hpp"

class Thomas : public IDescription {
public:
    explicit Thomas(std::string firstName = "Thomas", std::string lastName = "Hidalgo", int age = 22);
    ~Thomas() override = default;
    std::string getLastName() override ;
    std::string getFirstName() override ;
    int getAge() override ;
private:
    std::string _firstName;
    std::string _lastName;
    int _age;
};

#endif // OOP_ARCADE_2019_THOMAS_HPP
