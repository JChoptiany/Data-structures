#include <iostream>
#include "../Include/element.h"

template <typename T>
struct list
{
    std::shared_ptr<element<T>> first;

    void pushBack(const T& _value)
    {
        std::shared_ptr<element<T>> newElement = new element<T>;
        newElement -> value = _value;
        if (first == nullptr)
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
        while (current)
        {
            std::cout << current -> value << " ";
            current = current -> next;
        }
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

    list() : first(nullptr) {}
};