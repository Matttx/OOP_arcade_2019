/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** matteo.hpp
*/

#ifndef OOP_ARCADE_2019_MATTEO_HPP
#define OOP_ARCADE_2019_MATTEO_HPP

#include "../../../src/IDescription.hpp"

class Matteo : public IDescription {
public:
    explicit Matteo(std::string  firstName = "Matteo", std::string  lastName = "Fauchon", int age = 19);
    ~Matteo() override = default;
    std::string getLastName() override ;
    std::string getFirstName() override ;
    int getAge() override ;
private:
    std::string _firstName;
    std::string _lastName;
    int _age;
};

#endif // OOP_ARCADE_2019_MATTEO_HPP
