#pragma once

#include <iostream>
#include "queueElement.hpp"

template<typename T>
struct queue
{
    typedef queueElement<T> element;

    std::shared_ptr<element> head;

    queue();
    queue(const std::initializer_list<T>&);

    void enqueue(T);
    void dequeue();
    size_t size();
    T& front();
    T& back();
    void clear();
    bool empty();
    void swap(size_t, size_t);

private:
    T& at(size_t);
};

template<typename T>
queue<T>::queue()
{
    head = nullptr;
}

template<typename T>
queue<T>::queue(const std::initializer_list<T>& arguments)
{
    head = std::make_shared<element>(element(*arguments.begin()));
    std::shared_ptr<element> current = head;

    for(auto it = arguments.begin() + 1; it < arguments.end(); ++it)
    {
        current -> next = std::make_shared<element>(element(*it));
        current = current -> next;
    }
}

template<typename T>
void queue<T>::enqueue(const T _value)
{
    auto newElement = std::make_shared<element>(element(_value));

    if(empty())
    {
        head = newElement;
    }
    else
    {
        std::shared_ptr<element> current = head;

        while(current -> next)
        {
            current = current -> next;
        }
        current -> next = newElement;
    }
}

template<typename T>
void queue<T>::dequeue()
{
    head = head -> next;
}

template<typename T>
size_t queue<T>::size()
{
    if(empty())
    {
        return 0;
    }
    size_t result = 0;
    std::shared_ptr<element> current = head;

    while(current)
    {
        current = current -> next;
        ++result;
    }
    return result;
}

template<typename T>
T& queue<T>::front()
{
    return (head -> value);
}

template<typename T>
T& queue<T>::back()
{
    return at(size() - 1);
}

template<typename T>
void queue<T>::clear()
{
    head = nullptr;
}

template<typename T>
bool queue<T>::empty()
{
    return (!head);
}

template<typename T>
void queue<T>::swap(const size_t lhsIndex, const size_t rhsIndex)
{
    if(lhsIndex >= size() || lhsIndex < 0 || rhsIndex >= size() || rhsIndex < 0)
    {
        throw std::out_of_range("Out of range!");
    }
    T temp = at(lhsIndex);
    at(lhsIndex) = at(rhsIndex);
    at(rhsIndex) = temp;

}

template<typename T>
T& queue<T>::at(const size_t _index)
{
    if(_index >= size() || _index < 0)
    {
        throw std::out_of_range("Out of range!");
    }
    std::shared_ptr<element> current = head;

    for(size_t index = 0; index < _index; index++, current = current -> next);

    return current -> value;
}