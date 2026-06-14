/**
 * @file    main.cpp
 * @brief   Introduction to pointers and their applications in C/C++.
 *
 * @details
 * This file implements a small `Printer` class that demonstrates printing
 * elements of an `initializer_list<int>` using a range-based for loop and
 * also contains simple pointer usage examples. It is part of the
 * Section01_Introduction labs.
 *
 * @author  Mohamed Atef
 * @date    2026-06-15
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include <initializer_list>
using namespace std;

/*===========================================================================*
 *                     M A C R O S  &  F U N C T I O N - L I K E             *
 *                              M A C R O S                                  *
 *===========================================================================*/
/* None */

/*===========================================================================*
 *                           U S E R  T Y P E S                              *
 *===========================================================================*/
/* None */

/*===========================================================================*
 *                      S T A T I C  F U N C T I O N S                       *
 *===========================================================================*/
/* None */

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

/**
 * @brief  Entry point.
 *
 * @return 0 on success.
 */

 class Printer
 {
 public:
     Printer() = default;

     void print(const initializer_list<int> &il) const
     {
         for (int val : il)
         {
             cout << val << "\t";
         }
         cout << endl;
     }
 };
int main(void)
{
    /* Uniform Initialization */
    int i{12};
    int j{};
    int *ptr{};

    initializer_list<int> il{1,2,3,4,5,6,7,8,9};


    auto ptr2 = ptr; /* for auto *ptr */


    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "address of i: " << &i << endl;
    cout << "ptr (before): " << ptr << endl;

    ptr = &i;
    cout << "ptr (after = &i): " << ptr << " -> *ptr: " << *ptr << endl;

    ptr = &j;
    *ptr = 42;
    cout << "after *ptr = 42; j: " << j << endl;

    Printer printer;
    printer.print(il);


    return 0;
}
