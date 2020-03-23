/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus
*/

#include <iostream>
#include "EventBus.hpp"
#include "FunctionHandler.hpp"

template<typename EventType>
void EventBus::publish(EventType* event) {
    HandlerList *handlers = subscribers[typeid(EventType)];

    if (handlers == nullptr)
        return;
    
    for (auto &handler : *handlers) {
        if (handler != nullptr) {
            handler->exec(event);
            std::cout << "On a exécuté l'event" << std::endl;
        }
    }
    std::cout << "L'évènement est publié" << std::endl;
}

template<class T, class EventType>
void EventBus::subscribe(T * instance, void (T::*memberFunction)(EventType *)) {
    HandlerList *handlers = subscribers[typeid(EventType)];

    if (handlers == nullptr) {
        handlers = new HandlerList();
        subscribers[typeid(EventType)] = handlers;
        std::cout << "On créé handlers" << std::endl;
    }

    handlers->push_back(new FunctionHandler<T, EventType>(instance, memberFunction));
    std::cout << "On souscrit à l'évent" << std::endl;
}