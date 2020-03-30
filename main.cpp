#include "Include/list.h"

int main()
{
    auto *listInt = new list<int>;
    auto *listString = new list<std::string>;

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