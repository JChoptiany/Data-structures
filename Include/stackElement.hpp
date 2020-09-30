#include <memory>

template <typename T>
struct stackElement
{
    T value;
    std::shared_ptr<stackElement<T>> below;
    explicit stackElement(T _value) : value(_value), below(nullptr) {}
};