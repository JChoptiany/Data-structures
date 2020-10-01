#pragma once

#include <iostream>
#include <exception>
#include "singlyLinkedElement.hpp"

template <typename T>
struct singlyLinkedList
{
    typedef singlyLinkedElement<T> element;
    std::shared_ptr<element> first;

    singlyLinkedList();
    singlyLinkedList(const std::initializer_list<T>&);

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
    T min();
    T max();
    void insert(size_t, T);
    T& operator[](size_t);
    T& front();
    T& back();

private:
    std::shared_ptr<singlyLinkedElement<T>> access(size_t);
};

template<typename T>
singlyLinkedList<T>::singlyLinkedList()
{
    first = nullptr;
}

template<typename T>
singlyLinkedList<T>::singlyLinkedList(const std::initializer_list<T>& arguments)
{
    first = std::make_shared<element>(element(*arguments.begin()));
    std::shared_ptr<element> current = first;

    for(auto value = arguments.begin() + 1; value < arguments.end(); ++value)
    {
        current -> next = std::make_shared<element>(element(*value));
        current = current -> next;
    }
}

template <typename T>
void singlyLinkedList<T>::pushFront(const T _value)
{
    auto newElement = std::make_shared<element>(element(_value));

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
void singlyLinkedList<T>::pushBack(const T _value)
{
    auto newElement = std::make_shared<element>(element(_value));

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
        newElement -> next = nullptr;
    }
}

template <typename T>
void singlyLinkedList<T>::print(const std::string sign)
{
    if(size() != 0)
    {
        std::shared_ptr<element> current = first;
        while (current -> next)
        {
            std::cout << current -> value << sign;
            current = current -> next;
        }
        std::cout << current -> value;
        std::cout << std::endl;
    }
}

template <typename T>
size_t singlyLinkedList<T>::size()
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
void singlyLinkedList<T>::clear()
{
    first = nullptr;
}

template <typename T>
void singlyLinkedList<T>::assign(const T _value)
{
    std::shared_ptr<element> current = first;

    while (current)
    {
        current -> value = _value;
        current = current -> next;
    }
}

template <typename T>
bool singlyLinkedList<T>::empty()
{
    return (!first);
}

template <typename T>
size_t singlyLinkedList<T>::find(const T _value)
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
void singlyLinkedList<T>::remove(const size_t _index)
{
    if(_index >= size())
    {
        throw std::out_of_range("Out of range");
    }

    std::shared_ptr<element> current = first;

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
T& singlyLinkedList<T>::at(const size_t _index)
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
void singlyLinkedList<T>::popFront()
{
    if(size() == 0)
    {
        throw std::out_of_range("Container is already empty");
    }
    if(first)
    {
        first = first -> next;
    }
}

template <typename T>
void singlyLinkedList<T>::popBack()
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

        while (current -> next -> next)
        {
            current = current -> next;
        }

        current -> next = nullptr;
    }
}

template <typename T>
T& singlyLinkedList<T>::operator[](const size_t index)
{
    return at(index);
}

template <typename T>
T singlyLinkedList<T>::min()
{
    if(empty())
    {
        throw std::out_of_range("List is empty!");
    }

    T result = first -> value;
    std::shared_ptr<element> current = first;

    while (current)
    {
        if(current -> value < result)
        {
            result = current -> value;
        }
        current = current -> next;
    }
    return result;
}


template <typename T>
T singlyLinkedList<T>::max()
{
    if(empty())
    {
        throw std::out_of_range("Container is empty!");
    }

    T result = first -> value;
    std::shared_ptr<element> current = first;

    while (current)
    {
        if(current -> value > result)
        {
            result = current -> value;
        }
        current = current -> next;
    }
    return result;
}

template <typename T>
void singlyLinkedList<T>::insert(const size_t _index, const T _value)
{
    if(_index > size())
    {
        throw std::out_of_range("Out of range!");
    }
    if(_index == 0)
    {
        pushFront(_value);
    }
    else if(_index == size())
    {
        pushBack(_value);
    }
    else
    {
        auto newElement = std::make_shared<element>(_value);

        newElement -> next = access(_index-1) -> next;
        access(_index-1) -> next = newElement;
    }
}

template <typename T>
std::shared_ptr<singlyLinkedElement<T>> singlyLinkedList<T>::access(const size_t _index)
{
    if(_index >= size())
    {
        throw std::out_of_range("Out of range!");
    }

    std::shared_ptr<element> current = first;

    for(size_t index = 0; index < _index; index++, current = current -> next);

    return current;
}

template <typename T>
T& singlyLinkedList<T>::front()
{
    return at(0);
}

template <typename T>
T& singlyLinkedList<T>::back()
{
    return at(size() - 1);
}