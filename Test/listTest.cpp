#include "list.hpp"
#include <gtest/gtest.h>

TEST(listTest, listIntSizeShouldReturn0)
{
    list<int> listInt;
    ASSERT_EQ(listInt.size(), 0);
}

TEST(listTest, listIntSizeShouldReturn3)
{
    list<int> listInt;
    listInt.pushBack(1);
    listInt.pushBack(2);
    listInt.pushBack(3);
    ASSERT_EQ(listInt.size(), 3);
}

TEST(listTest, listIntSizeShouldReturn5)
{
    list<int> listInt;
    listInt.pushBack(1);
    listInt.pushBack(2);
    listInt.pushBack(3);
    listInt.pushBack(4);
    listInt.pushBack(5);
    ASSERT_EQ(listInt.size(), 5);
}

TEST(listTest, listStringSizeShouldReturn0)
{
    list<std::string> listString;
    ASSERT_EQ(listString.size(), 0);
}

TEST(listTest, listStringSizeShouldReturn3)
{
    list<std::string> listString;
    listString.pushBack("one");
    listString.pushBack("two");
    listString.pushBack("three");
    ASSERT_EQ(listString.size(), 3);
}

TEST(listTest, listStringSizeShouldReturn5)
{
    list<std::string> listString;
    listString.pushBack("one");
    listString.pushBack("two");
    listString.pushBack("three");
    listString.pushBack("four");
    listString.pushBack("five");
    ASSERT_EQ(listString.size(), 5);
}

TEST(listTest, listTSizeShouldReturn3)
{
    class T{};
    T t1, t2, t3;
    list<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    ASSERT_EQ(listT.size(), 3);
}

TEST(listTest, listTSizeShouldReturn5)
{
    class T{};
    T t1, t2, t3, t4, t5;
    list<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    ASSERT_EQ(listT.size(), 5);
}

TEST(listTest, listTSizeShouldReturn4)
{
    class T{};
    T t1, t2, t3, t4;
    list<T> listT;
    listT.pushFront(t1);
    listT.pushFront(t2);
    listT.pushFront(t3);
    listT.pushFront(t4);;
    ASSERT_EQ(listT.size(), 4);
}

TEST(listTest, listTEmptyShouldReturnTrue1)
{
    class T{};
    T t1, t2, t3, t4, t5;
    list<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    listT.clear();
    ASSERT_EQ(listT.empty(), true);
}

TEST(listTest, listTEmptyShouldReturnTrue2)
{
    class T{};
    list<T> listT;
    ASSERT_EQ(listT.empty(), true);
}

TEST(listTest, listTEmptyShouldReturnFalse)
{
    class T{};
    T t1, t2, t3, t4, t5;
    list<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    ASSERT_EQ(listT.empty(), false);
}

TEST(listTest, listStringFindShouldReturn2)
{
    list<std::string> listString;
    listString.pushBack("one");
    listString.pushBack("two");
    listString.pushBack("three");
    listString.pushBack("four");
    listString.pushBack("five");
    ASSERT_EQ(listString.find("three"), 2);
}

TEST(listTest, listIntFindShouldReturn4)
{
    list<int> listInt;
    listInt.pushBack(81);
    listInt.pushBack(175);
    listInt.pushBack(1877);
    listInt.pushBack(878452421);
    listInt.pushBack(17);
    ASSERT_EQ(listInt.find(17), 4);
}