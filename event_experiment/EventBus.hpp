/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus
*/

#ifndef EVENTBUS_HPP_
#define EVENTBUS_HPP_

#include <map>
#include <list>
#include <typeindex>
#include "AFunctionHandler.hpp"

typedef std::list<AFunctionHandler*> HandlerList;

class EventBus {
    public:
        template<typename EventType>
        void publish(EventType* event);
        template<class T, class EventType>
        void subscribe(T* instance, void (T::*memberFunction)(EventType *));
    private:
        std::map<std::type_index, HandlerList*> subscribers;
};

#endif /* !EVENTBUS_HPP_ */
