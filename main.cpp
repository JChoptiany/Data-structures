#include <iostream>

template <typename T>
struct element
{
    T value;
    element *next;
    element()
    {
        next = nullptr;
    }
};

template <typename T>
struct list
{
    element<T> *first;
    void pushBack(const T& _value)
    {
        element<T> *newElement = new element<T>;
        newElement->value = _value;
        if (first == nullptr)
        {
            first = newElement;
        }
        else
        {
            element<T> *temp = first;
            while (temp -> next)
            {
                temp = temp -> next;
            }
            temp -> next = newElement;
            newElement -> next = nullptr;
        }
    }
    void print()
    {
        element<T> *temp = first;
        while (temp)
        {
            std::cout << temp -> value << " ";
            temp = temp -> next;
        }
        std::cout << std::endl;
    }
    unsigned int size()
    {
        element<T> *temp = first;
        unsigned int result = 0;

        while (temp)
        {
            ++result;
            temp = temp -> next;
        }
        return result;
    }
    list()
    {
        first = nullptr;
    }
};

int main()
{
    list<int> *listInt = new list<int>;
    list<std::string> *listString = new list<std::string>;

    listInt -> pushBack(1);
    listInt -> pushBack(2);
    listInt -> pushBack(3);
    listInt -> print();
    std::cout << "Size of listInt = " << listInt -> size() << std::endl;

    listString -> pushBack("Dog");
    listString -> pushBack("Cat");
    listString -> pushBack("Elephant");
    listString -> pushBack("Turtle");
    listString -> pushBack("Tiger");
    listString -> print();
    std::cout << "Size of listString = " << listString -> size() << std::endl;

    delete listInt;
    delete listString;
    return 0;
}