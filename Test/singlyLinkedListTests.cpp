#include "singlyLinkedList.hpp"
#include <gtest/gtest.h>

TEST(singlyLinkedListTest, listIntSizeShouldReturn0)
{
    singlyLinkedList<int> listInt;
    ASSERT_EQ(listInt.size(), 0);
}

TEST(singlyLinkedListTest, listIntSizeShouldReturn3)
{
    singlyLinkedList<int> listInt;
    listInt.pushBack(1);
    listInt.pushBack(2);
    listInt.pushBack(3);
    ASSERT_EQ(listInt.size(), 3);
}

TEST(singlyLinkedListTest, listIntSizeShouldReturn5)
{
    singlyLinkedList<int> listInt;
    listInt.pushBack(1);
    listInt.pushBack(2);
    listInt.pushBack(3);
    listInt.pushBack(4);
    listInt.pushBack(5);
    ASSERT_EQ(listInt.size(), 5);
}

TEST(singlyLinkedListTest, listStringSizeShouldReturn0)
{
    singlyLinkedList<std::string> listString;
    ASSERT_EQ(listString.size(), 0);
}

TEST(singlyLinkedListTest, listStringSizeShouldReturn3)
{
    singlyLinkedList<std::string> listString;
    listString.pushBack("one");
    listString.pushBack("two");
    listString.pushBack("three");
    ASSERT_EQ(listString.size(), 3);
}

TEST(singlyLinkedListTest, listStringSizeShouldReturn5)
{
    singlyLinkedList<std::string> listString;
    listString.pushBack("one");
    listString.pushBack("two");
    listString.pushBack("three");
    listString.pushBack("four");
    listString.pushBack("five");
    ASSERT_EQ(listString.size(), 5);
}

TEST(singlyLinkedListTest, listTSizeShouldReturn3)
{
    class T{};
    T t1, t2, t3;
    singlyLinkedList<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    ASSERT_EQ(listT.size(), 3);
}

TEST(singlyLinkedListTest, listTSizeShouldReturn5)
{
    class T{};
    T t1, t2, t3, t4, t5;
    singlyLinkedList<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    ASSERT_EQ(listT.size(), 5);
}

TEST(singlyLinkedListTest, listTSizeShouldReturn4)
{
    class T{};
    T t1, t2, t3, t4;
    singlyLinkedList<T> listT;
    listT.pushFront(t1);
    listT.pushFront(t2);
    listT.pushFront(t3);
    listT.pushFront(t4);;
    ASSERT_EQ(listT.size(), 4);
}

TEST(singlyLinkedListTest, listTEmptyShouldReturnTrue1)
{
    class T{};
    T t1, t2, t3, t4, t5;
    singlyLinkedList<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    listT.clear();
    ASSERT_EQ(listT.empty(), true);
}

TEST(singlyLinkedListTest, listTEmptyShouldReturnTrue2)
{
    class T{};
    singlyLinkedList<T> listT;
    ASSERT_EQ(listT.empty(), true);
}

TEST(singlyLinkedListTest, listTEmptyShouldReturnFalse)
{
    class T{};
    T t1, t2, t3, t4, t5;
    singlyLinkedList<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    ASSERT_EQ(listT.empty(), false);
}

TEST(singlyLinkedListTest, listStringFindShouldReturn2)
{
    singlyLinkedList<std::string> listString;
    listString.pushBack("one");
    listString.pushBack("two");
    listString.pushBack("three");
    listString.pushBack("four");
    listString.pushBack("five");
    ASSERT_EQ(listString.find("three"), 2);
}

TEST(singlyLinkedListTest, listIntFindShouldReturn4)
{
    singlyLinkedList<int> listInt;
    listInt.pushBack(81);
    listInt.pushBack(175);
    listInt.pushBack(1877);
    listInt.pushBack(878452421);
    listInt.pushBack(17);
    ASSERT_EQ(listInt.find(17), 4);
}

TEST(singlyLinkedListTest, listTSizeShouldReturn6)
{
    class T{};
    T t1, t2, t3, t4, t5, t6, t7;
    singlyLinkedList<T> listT;
    listT.pushBack(t1);
    listT.pushBack(t2);
    listT.pushBack(t3);
    listT.pushBack(t4);
    listT.pushBack(t5);
    listT.pushBack(t6);
    listT.pushBack(t7);
    listT.remove(3);

    ASSERT_EQ(listT.size(), 6);
}

TEST(singlyLinkedListTest, listIntAtShouldReturn15)
{
    singlyLinkedList<int> listInt;
    listInt.pushBack(-14722);
    listInt.pushBack(7217);
    listInt.pushBack(15);
    listInt.pushBack(3147);
    listInt.pushBack(15487);
    ASSERT_EQ(listInt.at(2), 15);
}