/**
 * @file    main.cpp
 * @brief   Heap allocation and pointer cleanup in C/C++.
 *
 * @details
 * This lab demonstrates dynamic memory allocation with `new`, how to use
 * a heap-allocated integer through a pointer, and why `delete` is required
 * to release heap memory. It also shows resetting the pointer to `nullptr`
 * after deallocation for safer debugging.
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
 * @brief  Entry point for the heap pointer debugging lab.
 *
 * @return 0 on success.
 */
int main(void)
{
    int data = 5;
    int *ptr = &data;

    cout << "stack data: " << data << endl;
    cout << "stack address of data: " << &data << endl;
    cout << "ptr initially points to data: " << ptr << " -> " << *ptr << endl;

    ptr = new int(7);
    cout << "heap allocation: ptr = new int(7);" << endl;
    cout << "ptr now points to heap memory: " << ptr << " -> " << *ptr << endl;

    delete ptr;
    ptr = nullptr;

    cout << "after delete ptr; ptr reset to nullptr: " << ptr << endl;

    return 0;
}
