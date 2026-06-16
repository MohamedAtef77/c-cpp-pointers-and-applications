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
#include <algorithm>
#include <iostream>
using namespace std;

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

template<typename T, int size>
T* Begin(T(&ref)[size])
{
    return ref;
}

template<typename T, int size>
T* End(T(&ref)[size])
{
    return ref + size;
}

/**
 * @brief  Print a block of elements from a static array by reference.
 *
 * @tparam T     Element type of the array.
 * @param arrRef Reference to the array.
 *
 * The array size is deduced at compile time and preserved by the
 * reference parameter. This avoids the decay to a pointer that occurs
 * with a raw array argument.
 */
template<typename T, int size>
void Print(T(&arrRef)[size])
{
    cout << "Print(T(&arrRef)[size]): ";
    for (int i = 0; i < size; ++i)
    {
        cout << arrRef[i] << (i + 1 < size ? ' ' : '\n');
    }
    cout << "  (sizeof(arrRef) = " << sizeof(arrRef) << " bytes)\n";
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
    Print(arr1);

    cout << "arr2 in main: ";
    Print(arr2);

    cout << "arr3 in main: ";
    Print(arr3);

    arr3[0] = 100;
    int *p = arr3;
    *(p + 2) = 800;
    p[2] = 700;

    cout << "arr3 after pointer modification: ";
    Print(arr3);

    sort(begin(arr3), end(arr3));
    cout << "arr3 after sort with std::begin/end: ";
    Print(arr3);

    sort(Begin(arr3), End(arr3));
    cout << "arr3 after sort with Begin/End: ";
    Print(arr3);

    cout << "sizeof(arr3) in main = " << sizeof(arr3) << " bytes\n";
    cout << "element count in main = " << (sizeof(arr3) / sizeof(arr3[0])) << "\n";

    return 0;
}
