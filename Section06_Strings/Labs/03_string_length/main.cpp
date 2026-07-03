/**
 * @file    main.cpp
 * @brief   Demonstration of a function to print C-style strings.
 *
 * @details
 * This file defines and demonstrates a `Print` function that takes a
 * C-style string (a null-terminated character array) and prints it to
 * the console character by character until it encounters the null terminator.
 * The `main` function initializes a C-style string and calls `Print` to
 * display it.
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
 * @brief Prints a null-terminated C-style string to the console.
 *
 * @param str A pointer to the first character of the string to be printed.
 */
void Print(const char *str);

/**
 * @brief Returns the length of a null-terminated C-style string.
 *
 * @param str A pointer to the first character of the string.
 * @return The number of characters before the null terminator.
 */
int StringLength(const char *str);

void Print(const char *str)
{
    while(*str != '\0')
    {
        cout<< *str++;
    }

    cout << endl;
}

int StringLength(const char *str)
{
    int length = 0;

    while (*str != '\0')
    {
        ++length;
        ++str;
    }

    return length;
}

/**
 * @brief  Entry point for the C-style string printing lab.
 *
 * @return 0 on success.
 */
int main()
{
    /* Method 1: Initialize with a string literal, explicitly providing the size.
     * The size must be at least the number of characters + 1 for the null terminator.
     * "Mohamed" has 7 characters, so the array size is 7 + 1 = 8. */
    char str[8]{"Mohamed"};

    Print(str);
    cout << "Length: " << StringLength(str) << endl;
}