/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** FunctionHandler
*/

#ifndef FUNCTIONHANDLER_HPP_
#define FUNCTIONHANDLER_HPP_

#include "Event.hpp"
#include "AFunctionHandler.hpp"

template<class T, class EventType>
class FunctionHandler : public AFunctionHandler {
    typedef void (T::*MemberFunction)(EventType*);
    public:
        FunctionHandler(T *instance, MemberFunction memberFunction) : instance(instance), memberFunction(memberFunction) {};
        void call(Event *event) { 
            (instance->*memberFunction)(static_cast<EventType*>(event));
        };
    private:
        T *instance;
        MemberFunction memberFunction;
};

#endif /* !FUNCTIONHANDLER_HPP_ */
