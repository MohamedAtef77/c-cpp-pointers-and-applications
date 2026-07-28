/**
 * @file    main.cpp
 * @brief   Demonstration of C-style string copy and concatenation.
 *
 * @details
 * This file defines `StringCopy` and `StringConcatenate` functions that
 * operate on null-terminated character arrays, alongside the `Print` and
 * `StringLength` helpers from earlier labs. The `main` function builds a
 * full name by copying a first name into a buffer and concatenating a last
 * name onto it.
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

/**
 * @brief Copies a C-style string into a destination buffer.
 *
 * @param destination The destination buffer.
 * @param source The source string.
 */
void StringCopy(char *destination, const char *source);

/**
 * @brief Concatenates two C-style strings into a destination buffer.
 *
 * @param destination The destination buffer.
 * @param source The source string to append.
 */
void StringConcatenate(char *destination, const char *source);

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

void StringCopy(char *destination, const char *source)
{
    while (*source != '\0')
    {
        *destination = *source;
        ++destination;
        ++source;
    }

    *destination = '\0';
}

void StringConcatenate(char *destination, const char *source)
{
    while (*destination != '\0')
    {
        ++destination;
    }

    while (*source != '\0')
    {
        *destination = *source;
        ++destination;
        ++source;
    }

    *destination = '\0';
}

/**
 * @brief  Entry point for the C-style string copy/concatenate lab.
 *
 * @return 0 on success.
 */
int main()
{
    char firstName[20] = "Mohamed";
    char lastName[20] = "Atef";
    char fullName[40];

    StringCopy(fullName, firstName);
    StringConcatenate(fullName, lastName);

    Print(firstName);
    Print(lastName);
    Print(fullName);
}