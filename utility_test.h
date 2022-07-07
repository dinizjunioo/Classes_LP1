#ifndef _UTILITY_TEST_H_
#define _UTILITY_TEST_H_

#include <cstdlib>
#include <iostream>

#include "test_manager.h"
#include "list.h"


#define MERGE_1 NO


template <typename T>
void Utility_Operations_Tests()
{
    //=== TESTING UTILITY METHODS
    TestManager tm{ "Utility Operations Test Suite" };

#if MERGE_1
    {
        BEGIN_TEST(tm3, "Merge 1", "merging two interwoven regular sorted lists.");
        which_lib::list<int> list_a{ 0, 1, 3, 5, 7, 9 };        // List A
        which_lib::list<int> list_b{ 2, 4, 6, 8 };              // List B
        which_lib::list<int> list_r{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // List Result

        list_a.merge(list_b); // Merger B into A.
        EXPECT_EQ(list_r, list_a); // List A must be equal to list Result.
        EXPECT_TRUE(list_b.empty()); // List B must be empty (all nodes moved to A).

    }
#endif

    tm.summary();
    std::cout << "\n\n";
}

#endif