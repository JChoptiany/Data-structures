#include <memory>

template <typename T>
struct singlyLinkedElement
{
    T value;
    std::shared_ptr<singlyLinkedElement<T>> next;
    explicit singlyLinkedElement(T _value) : value(_value), next(nullptr) {}
};