#include <iostream>
#include <exception>
#include "element.hpp"

template <typename T>
struct list
{
    std::shared_ptr<element<T>> first;

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

    void print(std::string sign)
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

    unsigned int size()
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

    list() : first(nullptr) {}
};