/**
 * @file    main.cpp
 * @brief   Pointer debugging and pointer variable usage in C/C++.
 *
 * @details
 * This lab demonstrates pointer initialization, dereferencing, address
 * inspection, and pointer reset operations. The example shows how a pointer
 * can refer to an existing integer object, be used to modify that object,
 * and finally be reset to nullptr for safer debugging.
 *
 * @author  Mohamed Atef
 * @date    2026-06-15
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
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
 * @brief  Entry point for the pointer debugging lab.
 *
 * @return 0 on success.
 */
int main(void)
{
    int data = 5;
    int *ptr = &data;

    cout << "data: " << data << endl;
    cout << "address of data: " << &data << endl;
    cout << "ptr: " << ptr << endl;
    cout << "*ptr: " << *ptr << endl;
    cout << "ptr points to data: " << (ptr == &data ? "true" : "false") << endl;

    *ptr = 42;
    cout << "after *ptr = 42; data: " << data << endl;

    ptr = nullptr;
    cout << "ptr reset to nullptr: " << ptr << endl;

    return 0;
}
