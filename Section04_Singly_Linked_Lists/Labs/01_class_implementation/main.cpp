/**
 * @file    main.cpp
 * @brief   Singly linked list class implementation lab
 *
 * @details
 * Demonstrates a minimal node-based singly linked list using a `SingleList`
 * wrapper class. At this stage the class only exposes its shape (types,
 * constructors, and stubbed-out operations); the example shows that it can
 * be instantiated and queried before any operation is actually implemented.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include "single_list.h"
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
    SingleList<int> list;

    cout << "New list is empty: " << (list.Empty() ? "true" : "false") << "\n";
    cout << "Initial size: " << list.GetSize() << "\n";

    return 0;
}
