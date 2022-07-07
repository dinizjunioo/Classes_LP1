#ifndef _LIST_TESTS_H_
#define _LIST_TESTS_H_

#include <cstdlib>
#include <iostream>

#include "test_manager.h"
#include "list.h"


// ============================================================================
// TESTING LIST 
// ============================================================================

// Test default ctro's size and capacity initial values.
#define DEFAULT_CTRO YES

#define DEFAULT_CTRO_SIZE NO

#define DEFAULT_CTRO_INIT NO

#define DEFAULT_CTRO_RANGE NO

#define DEFAULT_CTRO_COPY NO

#define LIST_ASSIGN NO

#define LIST_INIT_ASSIGN NO

#define LIST_CLEAR NO

#define LIST_PUSH_FRONT NO

#define MOVE_SYNTAX_IMPLEMENTED NO
// ...
// ainda tem vários, pelo menos mais 10 testes
// ...


/// Tests the basic operations with a vector of integers.

void run_regular_list_tests(void)
{
    //=== TESTING BASIC OPERATIONS METHODS
    TestManager tm{ "Basic Operations Test Suite" };

#if DEFAULT_CTRO
    {
        BEGIN_TEST(tm, "DefaultConstructor", "default constructor");

        which_lib::list<int> list;

        EXPECT_EQ(list.size(), 0);
        //EXPECT_TRUE(list.empty());
    }
#endif

#if DEFAULT_CTRO_SIZE
    {
        BEGIN_TEST(tm, "ConstructorSize", "Constructor size");

        which_lib::list<int> list(10);

        EXPECT_EQ(list.size(), 10);
        EXPECT_FALSE(list.empty());
    }
#endif

#if DEFAULT_CTRO_INIT
    {
        BEGIN_TEST(tm, "ListContructor", "initializer list constructor.");

        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        EXPECT_EQ(list.size(), 5);
        EXPECT_FALSE(list.empty());


        int i{ 0 };
        for (auto it = list.cbegin(); it != list.cend(); ++i)
            EXPECT_EQ(i + 1, *it++);
    }
#endif

#if DEFAULT_CTRO_RANGE
    {
        BEGIN_TEST(tm, "RangeConstructor", "checking constructors with a range of values");
        // Range = the entire list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int> list2(list.begin(), list.end());

        EXPECT_EQ(list2.size(), 5);
        EXPECT_FALSE(list.empty());

        // recover elements to test
        auto i{ 1 };
        for (auto e : list2)
            EXPECT_EQ(e, i++);

        // Copy only part of the original range.
        which_lib::list<int> list3(std::next(list.begin(), 1), std::next(list.begin(), 3));
        EXPECT_EQ(list3.size(), 2);
        EXPECT_FALSE(list3.empty());

        auto it2 = std::next(list.begin(), 1);
        for (auto it = list3.begin(); it != list3.end(); ++it, ++it2)
            EXPECT_EQ(*it, *it2);
    }
#endif

#if DEFAULT_CTRO_COPY
    {
        BEGIN_TEST(tm, "CopyConstructor", "constructor copy values of another list.");
        // Range = the entire list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int> list2(list);

        EXPECT_EQ(list2.size(), 5);
        EXPECT_FALSE(list2.empty());

        // recover elements to test.

        auto i{ 1 };
        for (auto e : list2)
            EXPECT_EQ(e, i++);

        // Changing seq (the original)...
        auto it = std::next(list.begin(), 2);
        *it = 10;
        // ... should not alter the copy.
        i = 1;
        for (auto e : list2)
            EXPECT_EQ(e, i++);
    }
#endif

#if MOVE_SYNTAX_IMPLEMENTED

    {
         BEGIN_TEST(tm, "Molistonstructor", "move the elements from another");
         // Range = the entire list.
         which_lib::list<int> list{ 1, 2, 3, 4, 5 };
         which_lib::list<int> list2( std::move( list ) );

         EXPECT_EQ( list2.size(), 5 );
         EXPECT_FALSE( list2.empty() );

        // CHeck whether the copy worked.
         for( auto i{0u} ; i < list2.size() ; ++i )
             EXPECT_EQ( i+1, list2[i] );
    }
#endif

#if LIST_ASSIGN  
    {
        BEGIN_TEST(tm, "AssignOperator", "ASSIGN OPERATOR");
        // Range = the entire list.
        which_lib::list<int> list{ 1, 2, 3, 4, 5 };
        which_lib::list<int> list2;

        list2 = list;
        EXPECT_EQ(list2.size(), 5);
        EXPECT_FALSE(list2.empty());

        // recover elements to test.
        auto i{ 1 };
        for (auto e : list2)
            EXPECT_EQ(e, i++);;
    }
#endif

#if MOVE_SYNTAX_IMPLEMENTED  
     {
    // //     BEGIN_TEST(tm, "MoveAssignOperator", "MoveAssignOperator");
    // //     // Range = the entire list.
    // //     which_lib::list<int> list{ 1, 2, 3, 4, 5 };
    // //     which_lib::list<int> list2;

    // //     list2 = std::move( list );
    // //     EXPECT_EQ( list2.size(), 5 );
    // //     EXPECT_FALSE( list2.empty() );
    // //     EXPECT_EQ( list.size(), 0 );
    // //     EXPECT_EQ( list.capacity(), 0 );
    // //     EXPECT_TRUE( list.empty() );

    // //     // CHeck whether the copy worked.
    // //     for( auto i{0u} ; i < list2.size() ; ++i )
    // //         EXPECT_EQ( i+1, list2[i] );
    }
#endif

#if LIST_INIT_ASSIGN  
    {
        BEGIN_TEST(tm, "ListInitializerAssign", "initializer list assignment");
        // Range = the entire list.
        which_lib::list<int> list = { 1, 2, 3, 4, 5 };

        EXPECT_EQ(list.size(), 5);
        EXPECT_FALSE(list.empty());

        // recover elements to test.
        auto i{ 1 };
        for (auto e : list)
            EXPECT_EQ(e, i++);
    }
#endif

#if LIST_CLEAR  
    {
        BEGIN_TEST(tm, "Clear", "clear");
        // Range = the entire list.
        which_lib::list<int> list = { 1, 2, 3, 4, 5 };

        EXPECT_EQ(list.size(), 5);
        EXPECT_FALSE(list.empty());

        list.clear();

        EXPECT_EQ(list.size(), 0);
        EXPECT_TRUE(list.empty());
    }
#endif

#if LIST_PUSH_FRONT
    {
        BEGIN_TEST(tm, "PushFront", "PushFront");
        // #1 From an empty list.
        which_lib::list<int> list;

        EXPECT_TRUE(list.empty());
        for (auto i{ 0 }; i < 5; ++i)
        {
            list.push_front(i + 1);
            EXPECT_EQ(list.size(), i + 1);
        }
        EXPECT_FALSE(list.empty());

        auto i{ 5 };
        for (const auto& e : list)
            EXPECT_EQ(e, i--);


        // REmove all elements.
        list.clear();
        EXPECT_TRUE(list.empty());
        for (auto i{ 0u }; i < 5; ++i)
        {
            list.push_front(i + 1);
            EXPECT_EQ(list.size(), i + 1);
        }
        EXPECT_FALSE(list.empty());

        i = 5;
        for (const auto& e : list)
        {
            EXPECT_EQ(e, i--);
        }
    }
#endif

        tm.summary();
    std::cout << "\n\n";
}

#endif
