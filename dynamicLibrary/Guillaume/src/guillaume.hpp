/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** guillaume.hpp
*/

#ifndef OOP_ARCADE_2019_GUILLAUME_HPP
#define OOP_ARCADE_2019_GUILLAUME_HPP

#include "IDescription.hpp"

class Guillaume : public IDescription {
public:
    explicit Guillaume(std::string  firstName = "Guillaume", std::string  lastName = "Bonnet", int age = 19);
    ~Guillaume() override = default;
    std::string getLastName() override ;
    std::string getFirstName() override ;
    int getAge() override ;
private:
    std::string _firstName;
    std::string _lastName;
    int _age;
};

#endif // OOP_ARCADE_2019_GUILLAUME_HPP
