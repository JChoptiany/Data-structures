#pragma once

#include <iostream>
#include <exception>
#include "element.hpp"

template <typename T>
struct list
{
    std::shared_ptr<element<T>> first;

    list() : first(nullptr) {}

    void pushFront(T);
    void pushBack(T);
    void print(std::string = " ");
    size_t size();
    void clear();
    void assign(T);
    bool empty();
    size_t find(T);
    void remove (size_t);
    T& at(size_t);
    void popFront();
    void popBack();
};

template <typename T>
void list<T>::pushFront(const T _value)
{
    auto newElement = std::make_shared<element<T>>(element<T>(_value));

    if (!first)
    {
        first = newElement;
    }
    else
    {
        newElement->next = first;
        first = newElement;
    }
}

template <typename T>
void list<T>::pushBack(const T _value)
{
    auto newElement = std::make_shared<element<T>>(element<T>(_value));

    if (!first)
    {
        first = newElement;
    }
    else
    {
        std::shared_ptr<element<T>> current = first;
        while (current -> next)
        {
            current = current -> next;
        }
        current -> next = newElement;
        newElement -> next = nullptr;
    }
}

template <typename T>
void list<T>::print(const std::string sign)
{
    if(size() != 0)
    {
        std::shared_ptr<element<T>> current = first;
        while (current -> next != nullptr)
        {
            std::cout << current -> value << sign;
            current = current -> next;
        }
        std::cout << current -> value;
        std::cout << std::endl;
    }
}

template <typename T>
size_t list<T>::size()
{
    std::shared_ptr<element<T>> current = first;
    unsigned int result = 0;

    while (current)
    {
        ++result;
        current = current -> next;
    }
    return result;
}

template <typename T>
void list<T>::clear()
{
    first = nullptr;
}

template <typename T>
void list<T>::assign(const T _value)
{
    std::shared_ptr<element<T>> current = first;

    while (current)
    {
        current -> value = _value;
        current = current -> next;
    }
}

template <typename T>
bool list<T>::empty()
{
    return (!first);
}

template <typename T>
size_t list<T>::find(const T _value)
{
    std::shared_ptr<element<T>> current = first;
    int index = 0;

    while (current)
    {
        if (current -> value == _value)
        {
            return index;
        }
        else
        {
            ++index;
            current = current -> next;
        }
    }
    return -1;
}

template <typename T>
void list<T>::remove(const size_t _index)
{
    if(_index >= size())
    {
        throw std::out_of_range("Out of range");
    }

    std::shared_ptr<element<T>> current = first;

    if(_index == 0)
    {
        first = current -> next;
    }
    else
    {
        for(unsigned index = 1; index < _index; index++, current = current -> next);

        current -> next = current -> next -> next;
    }
}

template <typename T>
T& list<T>::at(const size_t _index)
{
    if(_index >= size())
    {
        throw std::out_of_range("Out of range!");
    }
    std::shared_ptr<element<T>> current = first;

    for(size_t index = 0; index < _index; index++, current = current -> next);

    return current -> value;
}

template <typename T>
void list<T>::popFront()
{
    if(size() == 0)
    {
        throw std::out_of_range("Container is already empty");
    }
    if(first != nullptr)
    {
        first = first -> next;
    }
}

template <typename T>
void list<T>::popBack()
{
    if(size() == 0)
    {
        throw std::out_of_range("Container is already empty");
    }
    if(size() == 1)
    {
        first = nullptr;
    }
    else if(size() > 1)
    {
        std::shared_ptr<element<T>> current = first;

        while (current -> next -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = nullptr;
    }
}