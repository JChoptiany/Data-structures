#pragma once

#include <exception>
#include "stackElement.hpp"

template<typename T>
struct stack
{
    typedef stackElement<T> element;
    std::shared_ptr<element> top;

    stack() : top(nullptr) {}

    void push(T);
    void pop();
    bool empty();
    void clear();
    size_t size();
    T& peek();
};

template<typename T>
void stack<T>::push(const T _value)
{
    auto newElement = std::make_shared<element>(_value);

    if(!top)
    {
        top = newElement;
    }
    else
    {
        newElement -> below = top;
        top = newElement;
    }
}

template<typename T>
void stack<T>::pop()
{
    if(empty())
    {
        throw std::out_of_range("Stack is already empty!");
    }
    top = top -> below;
}

template<typename T>
bool stack<T>::empty()
{
    return(!top);
}

template<typename T>
void stack<T>::clear()
{
    top = nullptr;
}

template<typename T>
size_t stack<T>::size()
{
    size_t result = 0;
    std::shared_ptr current = top;

    while(current)
    {
        current = current -> below;
        ++result;
    }
    return result;
}

template<typename T>
T& stack<T>::peek()
{
    if(empty())
    {
        throw std::out_of_range("Stack is empty!");
    }
    return top -> value;
}