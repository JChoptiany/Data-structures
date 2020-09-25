#pragma once

#include <iostream>
#include <exception>
#include "element.hpp"

template <typename T>
struct list
{
    std::shared_ptr<element<T>> first;

    list() : first(nullptr) {}

    void pushFront(const T& _value)
    {
        auto newElement = std::make_shared<element<T>>(element<T>());
        newElement -> value = _value;

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

    void pushBack(const T& _value)
    {
        auto newElement = std::make_shared<element<T>>(element<T>());
        newElement -> value = _value;

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

    void print()
    {
        std::shared_ptr<element<T>> current = first;
        while (current->next != nullptr)
        {
            std::cout << current -> value << ' ';
            current = current -> next;
        }
        std::cout << current -> value;

        std::cout << std::endl;
    }

    void print(const std::string sign)
    {
        std::shared_ptr<element<T>> current = first;
        while (current->next != nullptr)
        {
            std::cout << current -> value << sign;
            current = current -> next;
        }
        std::cout << current -> value;

        std::cout << std::endl;
    }

    size_t size()
    {
        std::shared_ptr<element<T>> temp = first;
        unsigned int result = 0;

        while (temp)
        {
            ++result;
            temp = temp -> next;
        }
        return result;
    }

    void clear()
    {
        first = nullptr;
    }

    void assign(const T _value)
    {
        std::shared_ptr<element<T>> temp = first;

        while (temp)
        {
            temp -> value = _value;
            temp = temp -> next;
        }
    }

    bool empty()
    {
        return (!first);
    }

    int find(const T _value)
    {
        std::shared_ptr<element<T>> temp = first;
        int index = 0;

        while (temp)
        {
            if (temp -> value == _value)
            {
                return index;
            }
            else
            {
                ++index;
                temp = temp -> next;
            }
        }
        return -1;
    }

    void remove(const size_t _index)
    {
        if(_index >= size())
        {
            throw std::out_of_range("Out of range");
        }

        std::shared_ptr<element<T>> temp = first;

        if(_index == 0)
        {
            first = temp -> next;
        }

        for(unsigned index = 1; index < _index; index++, temp = temp -> next);

        temp -> next = temp -> next -> next;
    }

    T& at(const size_t _index)
    {
        if(_index >= size())
        {
            throw std::out_of_range("Out of range!");
        }
        std::shared_ptr<element<T>> temp = first;

        for(size_t index = 0; index < _index; index++, temp = temp -> next);

        return temp -> value;

    }
};