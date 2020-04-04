#include "list.hpp"
#include <gtest/gtest.h>

TEST(listTest, listIntSizeShouldReturn0)
{
    auto listInt = std::make_shared<list<int>>(list<int>());
    ASSERT_EQ(listInt -> size(), 0);
}

TEST(listTest, listIntSizeShouldReturn3)
{
    auto listInt = std::make_shared<list<int>>(list<int>());
    listInt -> pushBack(1);
    listInt -> pushBack(2);
    listInt -> pushBack(3);
    ASSERT_EQ(listInt -> size(), 3);
}

TEST(listTest, listIntSizeShouldReturn5)
{

    auto listInt = std::make_shared<list<int>>(list<int>());
    listInt -> pushBack(1);
    listInt -> pushBack(2);
    listInt -> pushBack(3);
    listInt -> pushBack(4);
    listInt -> pushBack(5);
    ASSERT_EQ(listInt -> size(), 5);
}

TEST(listTest, listStringSizeShouldReturn0)
{
    auto listString = std::make_shared<list<std::string>>(list<std::string>());
    ASSERT_EQ(listString -> size(), 0);
}

TEST(listTest, listStringSizeShouldReturn3)
{
    auto listString = std::make_shared<list<std::string>>(list<std::string>());
    listString -> pushBack("one");
    listString -> pushBack("two");
    listString -> pushBack("three");
    ASSERT_EQ(listString -> size(), 3);
}

TEST(listTest, listStringSizeShouldReturn5)
{
    auto listString = std::make_shared<list<std::string>>(list<std::string>());
    listString -> pushBack("one");
    listString -> pushBack("two");
    listString -> pushBack("three");
    listString -> pushBack("four");
    listString -> pushBack("five");
    ASSERT_EQ(listString -> size(), 5);
}

TEST(listTest, listTSizeShouldReturn0)
{
    class T{};
    auto listT = std::make_shared<list<T>>(list<T>());
    ASSERT_EQ(listT -> size(), 0);
}

TEST(listTest, listTSizeShouldReturn3)
{
    class T{};
    T t1, t2, t3;
    auto listT = std::make_shared<list<T>>(list<T>());
    listT -> pushBack(t1);
    listT -> pushBack(t2);
    listT -> pushBack(t3);
    ASSERT_EQ(listT -> size(), 3);
}

TEST(listTest, listTSizeShouldReturn5)
{
    class T{};
    T t1, t2, t3, t4, t5;
    auto listT = std::make_shared<list<T>>(list<T>());
    listT -> pushBack(t1);
    listT -> pushBack(t2);
    listT -> pushBack(t3);
    listT -> pushBack(t4);
    listT -> pushBack(t5);
    ASSERT_EQ(listT -> size(), 5);
}
