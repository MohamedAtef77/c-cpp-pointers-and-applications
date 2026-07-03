/**
 * @file    main.cpp
 * @brief   Copy and move semantics for a singly linked list
 *
 * @details
 * Demonstrates how a `SingleList` behaves when it is copied or moved, and
 * how each instance manages its own nodes.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include "doubly_list.h"
using namespace std;

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

/**
 * @brief  Entry point for the copy semantics linked list lab.
 *
 * @return 0 on success.
 */
int main()
{
    SingleList<int> list;
    list.Add(10);
    list.Add(20);
    list.Add(30);

    cout << "Initial list: ";
    list.Print(cout);
    cout << "\n";

    list.Insert(1, 25);
    list.Erase(2);

    cout << "After insert/erase: ";
    list.Print(cout);
    cout << "\n";

    cout << "Front: " << list.Front() << "\n";
    cout << "Element at index 1: " << list.At(1) << "\n";
    cout << "Size: " << list.GetSize() << "\n";
    cout << "Empty: " << (list.Empty() ? "true" : "false") << "\n";

    list.Clear();
    cout << "After clear, empty: " << (list.Empty() ? "true" : "false") << "\n";

    return 0;
}
