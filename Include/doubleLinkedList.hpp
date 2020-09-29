#pragma once

#include <iostream>
#include <exception>
#include "doubleLinkedElement.hpp"

template <typename T>
struct doubleLinkedList
{
    typedef doubleLinkedElement<T> element;
    std::shared_ptr<element> first;

    doubleLinkedList() : first(nullptr) {}

    void pushFront(T);
    void pushBack(T);
    size_t size();
    void print(std::string = " ");
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
void doubleLinkedList<T>::pushFront(const T _value)
{
    auto newElement = std::make_shared<element>(element(_value));

    if (!first)
    {
        first = newElement;
    }
    else
    {
        newElement -> next = first;
        newElement -> next -> previous = newElement;
        first = newElement;
    }
}

template <typename T>
void doubleLinkedList<T>::pushBack(const T _value)
{
    auto newElement = std::make_shared<element>(element(_value, first));

    if (!first)
    {
        first = newElement;
    }
    else
    {
        std::shared_ptr<element> current = first;
        while (current -> next)
        {
            current = current -> next;
        }

        current -> next = newElement;
        newElement -> previous = current;
    }
}

template <typename T>
size_t doubleLinkedList<T>::size()
{
    std::shared_ptr<element> current = first;
    unsigned int result = 0;

    while (current)
    {
        ++result;
        current = current -> next;
    }
    return result;
}

template <typename T>
void doubleLinkedList<T>::print(const std::string sign)
{
    if(size() != 0)
    {
        std::shared_ptr<element> current = first;
        while (current -> next != nullptr)
        {
            std::cout << current -> value << sign;
            current = current -> next;
        }
        std::cout << current -> value;
        std::cout << std::endl;
    }
}

template<typename T>
void doubleLinkedList<T>::clear()
{
    first = nullptr;
}
template<typename T>
void doubleLinkedList<T>::assign(const T _value)
{
    std::shared_ptr<element> current = first;

    while (current)
    {
        current -> value = _value;
        current = current -> next;
    }
}

template<typename T>
bool doubleLinkedList<T>::empty()
{
    return (!first);
}

template <typename T>
size_t doubleLinkedList<T>::find(const T _value)
{
    std::shared_ptr<element> current = first;
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
void doubleLinkedList<T>::remove(size_t _index)
{
    if(_index >= size())
    {
        throw std::out_of_range("Out of range");
    }

    std::shared_ptr<element> current = first;

    if(_index == 0)
    {
        first -> next -> previous = nullptr;
        first = current -> next;
    }
    else
    {
        for(unsigned index = 1; index < _index; index++, current = current -> next);

        if(current -> next -> next)
        {
            current -> next -> next -> previous = current;
        }
        current -> next = current -> next -> next;
    }
}

template <typename T>
T& doubleLinkedList<T>::at(const size_t _index)
{
    if(_index >= size())
    {
        throw std::out_of_range("Out of range!");
    }
    std::shared_ptr<element> current = first;

    for(size_t index = 0; index < _index; index++, current = current -> next);

    return current -> value;
}

template <typename T>
void doubleLinkedList<T>::popFront()
{
    if(size() == 0)
    {
        throw std::out_of_range("Container is already empty");
    }
    if(first != nullptr)
    {
        first -> next -> previous = nullptr;
        first = first -> next;
    }
}

template <typename T>
void doubleLinkedList<T>::popBack()
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
        std::shared_ptr<element> current = first;

        while (current -> next -> next != nullptr)
        {
            current = current -> next;
        }

        current -> next = nullptr;
    }
}