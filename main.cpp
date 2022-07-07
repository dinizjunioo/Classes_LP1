#include<iostream>

#include "main.h"
#include "list_tests.h"
//#include "utility_test.h"


//void run_regular_list_tests(void);
void Utility_Operations_Tests(void);


int main(void)
{

    std::cout << ">>> Testing list with integers.\n";
    run_regular_list_tests();

    //std::cout << ">>> Testing iterators methods.\n";
    //run_regular_vector_tests(values_i, source_i);

    //std::cout << ">>> Testing utility operations.\n";
    //Utility_Operations_Tests();

    return 1;
}