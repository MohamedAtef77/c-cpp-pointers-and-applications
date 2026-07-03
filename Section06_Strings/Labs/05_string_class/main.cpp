/**
 * @file    main.cpp
 * @brief   Demonstration of a simple String class.
 *
 * @details
 * This file implements a small String class that manages a dynamically
 * allocated C-style string and supports construction, copying, moving,
 * appending, and printing.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include "string.h"
using namespace std;

/**
 * @brief  Entry point for the string class lab.
 *
 * @return 0 on success.
 */
int main()
{
    String firstName("Mohamed");
    String lastName("Atef");
    String fullName(firstName);

    fullName.Append(" ");
    fullName.Append(lastName.c_str());

    firstName.Print();
    lastName.Print();
    fullName.Print();
    cout << "Size: " << fullName.GetSize() << endl;
}