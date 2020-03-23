/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AFunctionHandler
*/

#ifndef AFUNCTIONHANDLER_HPP_
#define AFUNCTIONHANDLER_HPP_

#include "Event.hpp"

class AFunctionHandler {
    public:
        void exec(Event* event);
    private:
        virtual void call(Event *event) = 0;
};

#endif /* !AFUNCTIONHANDLER_HPP_ */
