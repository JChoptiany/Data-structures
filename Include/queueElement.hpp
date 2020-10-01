#pragma once

#include <memory>

template<typename T>
struct queueElement
{
    T value;
    std::shared_ptr<queueElement<T>> next;
    explicit queueElement(T _value) : value(_value), next(nullptr) {}
};