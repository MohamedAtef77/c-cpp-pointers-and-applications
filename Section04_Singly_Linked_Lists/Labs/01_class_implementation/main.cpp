/**
 * @file    main.cpp
 * @brief   Singly linked list class implementation lab
 *
 * @details
 * Demonstrates a minimal node-based singly linked list using a `SingleList`
 * wrapper class. The example shows how the list is created, populated, and
 * traversed from the head node.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
using namespace std;

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

/**
 * @brief  Entry point for the singly linked list class implementation lab.
 *
 * @return 0 on success.
 */
int main()
{
    // Uninitialized array: elements hold indeterminate values.
    int arr1[5]; // Uninitialized array

    // Default/value initialization (C++11): all elements zero-initialized.
    int arr2[5]{}; // Default initialization (C++11)

    // Explicitly sized, initialized array.
    int arr3[5]{ 1, 2, 3, 4, 5 }; // Initialized array

    // Size deduction from initializer list; size need not be specified.
    int arr4[]{ 1, 2, 3, 4, 5 }; // Size deduced from initializer

    // Helper lambda to print arrays.
    auto print = [](const char* name, const int* a, size_t n) {
        cout << name << ": ";
        for (size_t i = 0; i < n; ++i)
        {
            cout << a[i] << (i + 1 < n ? ' ' : '\n');
        }
    };

    // Print all arrays. Note: `arr1` contains indeterminate values.
    print("arr1", arr1, 5);
    print("arr2", arr2, 5);
    print("arr3", arr3, 5);
    print("arr4", arr4, sizeof(arr4) / sizeof(arr4[0]));

    return 0;
}
