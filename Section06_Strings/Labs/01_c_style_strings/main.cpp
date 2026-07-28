/**
 * @file    main.cpp
 * @brief   Demonstration of C-style string initialization.
 *
 * @details
 * This file shows various ways to declare and initialize C-style strings
 * (null-terminated character arrays) in C++.
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
 * @brief  Entry point for the C-style string initialization lab.
 *
 * @return 0 on success.
 */
int main()
{
    /* Method 1: Initialize with a string literal, explicitly providing the size.
     * The size must be at least the number of characters + 1 for the null terminator.
     * "Mohamed" has 7 characters, so the array size is 7 + 1 = 8. */
    char str[8]{"Mohamed"};
    cout << str << endl;

    /* Method 2: Let the compiler deduce the size from the string literal.
     * The compiler will automatically allocate 5 characters (4 for "Atef" + 1 for '\0'). */
    char str2[] = "Atef"; /* Size is 5 */
    cout << str2 << endl;

    /* Method 3: Initialize with an initializer list of characters.
     * You must explicitly include the null terminator '\0'. */
    char str3[] = {'C', '+', '+', '\0'};
    cout << str3 << endl;
}
