#ifndef _ITERATORS_TEST_H_
#define _ITERATORS_TEST_H_

#include <cstdlib>
#include <iostream>

#include "test_manager.h"
#include "list.h"

// ============================================================================
// TESTING ITERATORS
// ============================================================================

// Test default ctro's size and capacity initial values.
#define LIST_BEGIN NO

#define LIST_CBEGIN NO

#define LIST_END NO

#define LIST_CEND NO

#define LIST_OPERATOR_PLUS_LEFT NO

#define LIST_OPERATOR_PLUS_RIGHT NO

#define LIST_OPERATOR_MINUS_LEFT NO

#define LIST_OPERATOR_MINUS_RIGHT NO

#define LIST_OPERATOR_STAR NO
/// Tests the basic operations with a vector of integers.
template <typename T>
void iterator_tests(void)
{
    //=== TESTING BASIC OPERATIONS METHODS
    TestManager tm{ "Iterator Test Suite" };

#if LIST_BEGIN
    {
        BEGIN_TEST(tm2, "begin", "list.begin()");

        which_lib::list<int> list{ 1, 2, 4, 5, 6 };
        which_lib::list<int>::iterator it = list.begin();
        EXPECT_EQ(1, *it);

        auto list2 = list;
        it = list2.begin();
        EXPECT_EQ(1, *it);

        auto list3 = list;
        it = list3.begin();
        EXPECT_EQ(1, *it);

        // which_lib::list<int> vec4 =  { 1, 2, 4, 5, 6 };
        which_lib::list<int> list4 = { 10, 11, 12, 13, 14 };
        it = list4.begin();
        EXPECT_EQ(10, *it);
    }
#endif

#if LIST_CBEGIN
    {
        BEGIN_TEST(tm2, "cbegin", "list.cbegin()");

        which_lib::list<int> list{ 1, 2, 4, 5, 6 };
        which_lib::list<int>::const_iterator cit = list.cbegin();
        EXPECT_EQ(1, *cit);

        auto list2 = list;
        cit = list2.cbegin();
        EXPECT_EQ(1, *cit);

        auto list3 = list;
        cit = list3.cbegin();
        EXPECT_EQ(1, *cit);

        which_lib::list<int> list4 = { 10, 11, 12, 13, 14 };
        cit = list4.cbegin();
        EXPECT_EQ(10, *cit);
    }
#endif

#if LIST_END
    {
        BEGIN_TEST(tm2, "end", "list.end()");

        which_lib::list<int> list{ 1, 2, 4, 5, 6 };
        which_lib::list<int>::iterator it = std::next(list.begin(), 5);
        EXPECT_EQ(it, list.end());

        auto list2 = list;
        it = std::next(list2.begin(), 5);
        EXPECT_EQ(it, list2.end());

        auto list3 = list;
        it = std::next(list3.begin(), 5);
        EXPECT_EQ(it, list3.end());

        // which_lib::list<int> vec4 =  { 1, 2, 4, 5, 6 };
        which_lib::list<int> list4 = { 10, 11, 12, 13, 14 };
        it = std::next(list4.begin(), 5);
        EXPECT_EQ(it, list4.end());
    }
#endif

#if LIST_CEND
    {
        BEGIN_TEST(tm2, "cend", "list.cend()");

        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int>::const_iterator it = std::next(list.cbegin(), 5);
        EXPECT_EQ(it, list.cend());

        auto list2 = list;
        it = std::next(list2.cbegin(), 5);
        EXPECT_EQ(it, list2.cend());

        auto list3 = list;
        it = std::next(list3.cbegin(), 5);
        EXPECT_EQ(it, list3.cend());

        which_lib::list<int> list4 = { 10, 11, 12, 13, 14 };
        it = std::next(list4.cbegin(), 5);
        EXPECT_EQ(it, list4.cend());
    }
#endif

#if LIST_OPERATOR_PLUS_LEFT
    {
        BEGIN_TEST(tm2, "operator++()", "Preincrement, ++it");

        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        int expected[]{ 1, 2, 3, 4, 5 };

        auto it = list.begin();
        for (const auto& e : expected)
        {
            EXPECT_EQ(*it, e);
            ++it;
        }
    }
#endif

#if LIST_OPERATOR_PLUS_RIGHT
    {
        BEGIN_TEST(tm2, "operator++(int)", "Postincrement, it++");

        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        int expected[]{ 1, 2, 3, 4, 5 };

        auto it = list.begin();
        for (const auto& e : expected)
        {
            EXPECT_EQ(*it, e);
            it++;
        }
    }
#endif

#if LIST_OPERATOR_MINUS_LEFT
    {
        BEGIN_TEST(tm2, "operator--()", "Preincrement, --it");

        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        int expected[]{ 5, 4, 3, 2, 1 };

        auto it = list.end();
        for (const auto& e : expected)
        {
            --it;
            EXPECT_EQ(*it, e);
        }
    }
#endif

#if LIST_OPERATOR_MINUS_RIGHT
    {
        BEGIN_TEST(tm2, "operator--(int)", "Postincrement, it--");

        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        int expected[]{ 5, 4, 3, 2, 1 };

        auto it = list.end();
        for (const auto& e : expected)
        {
            it--;
            EXPECT_EQ(*it, e);
        }
    }
#endif

#if LIST_OPERATOR_STAR
    {
        BEGIN_TEST(tm2, "operator*()", " x = *it1");

        which_lib::list<int> list{ 1, 2, 3, 4, 5, 6 };

        auto it = list.begin();
        int i{ 1 };
        while (it != list.end())
            EXPECT_EQ(*it++, i++);
    }
#endif
    tm.summary();
    std::cout << "\n\n";
}

#endif

