/**
 * @file    main.cpp
 * @brief   Demonstrates passing static arrays to functions in C++.
 *
 * @details
 * Shows how C-style arrays are passed as pointer-like parameters when
 * used in function calls. The lab compares explicit size passing with
 * compile-time array size calculation in the caller and demonstrates
 * pointer arithmetic on an array element.
 *
 * The function parameter `int *ptr` is equivalent to `int ptr[]` and does
 * not preserve the original array size.
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
 * @brief  Print a block of integers from an array.
 *
 * @param ptr   Pointer to the first element of the array.
 * @param size  Number of elements to print.
 */
void Print(int *ptr, int size)
{
    cout << "Print(int *ptr, int size): ";
    for (int i = 0; i < size; ++i)
    {
        cout << ptr[i] << (i + 1 < size ? ' ' : '\n');
    }
    cout << "  (sizeof(ptr) = " << sizeof(ptr) << " bytes)\n";
}

/**
 * @brief  Entry point demonstrating array argument passing.
 *
 * @return 0 on success.
 */
int main()
{
    int arr1[5];          // Uninitialized array
    int arr2[5]{};        // Value-initialized array (all zeros)
    int arr3[5]{1, 2, 3, 4, 5};

    for (int i = 0; i < 5; ++i)
    {
        arr1[i] = (i + 1) * 10;
    }

    cout << "arr1 in main: ";
    Print(arr1, 5);

    cout << "arr2 in main: ";
    Print(arr2, 5);

    cout << "arr3 in main: ";
    Print(arr3, 5);

    arr3[0] = 100;
    int *p = arr3;
    *(p + 2) = 800;
    p[2] = 700;

    cout << "arr3 after pointer modification: ";
    Print(arr3, 5);

    cout << "sizeof(arr3) in main = " << sizeof(arr3) << " bytes\n";
    cout << "element count in main = " << (sizeof(arr3) / sizeof(arr3[0])) << "\n";

    return 0;
}
