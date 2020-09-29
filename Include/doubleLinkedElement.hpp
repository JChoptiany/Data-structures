#include <memory>

template <typename T>
struct doubleLinkedElement
{
    T value;
    std::shared_ptr<doubleLinkedElement<T>> previous;
    std::shared_ptr<doubleLinkedElement<T>> next;

    doubleLinkedElement() : value(nullptr), previous(nullptr), next(nullptr) {}
    explicit doubleLinkedElement(T _value) : value(_value), previous(nullptr), next(nullptr) {}
    explicit doubleLinkedElement(T _value, std::shared_ptr<doubleLinkedElement<T>> _previous) : value(_value), previous(_previous), next(nullptr) {}
};