/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** EventBus.cpp
*/

#include "EventBus.hpp"

engine::eventbus::EventBus::ICallbackHandler::~ICallbackHandler() = default;

engine::eventbus::EventBus::EventBus() = default;

engine::eventbus::EventBus::~EventBus() {
    for (const auto &_cbHandler : _cbHandlers)
        for (const auto &callback : _cbHandler.second)
            delete &callback.get();
}
