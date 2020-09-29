#include <memory>

template <typename T>
struct element
{
    T value;
    std::shared_ptr<element<T>> next;
    explicit element(T _value) : value(_value), next(nullptr) {}
};