#include <memory>

template <typename T>
struct element
{
    T value;
    std::shared_ptr<element<T>> next;
    element() : next(nullptr) {}
};