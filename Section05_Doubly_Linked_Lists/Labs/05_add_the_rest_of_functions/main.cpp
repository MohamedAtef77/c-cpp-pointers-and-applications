/**
 * @file    main.cpp
 * @brief   Insert, erase, front, and back operations on a doubly linked list
 *
 * @details
 * Demonstrates the remaining `DoubleList` operations: inserting and erasing
 * elements by index, reading the front and back elements, checking size and
 * emptiness, and clearing the list.
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
 * @brief  Entry point for the "rest of the functions" linked list lab.
 *
 * @return 0 on success.
 */
int main()
{
    DoubleList<int> list;
    list.push_back(10);
    list.push_back(20);
    list.push_back(30);

    cout << "Initial list: ";
    for (Node<int>* node = list.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    list.insert(1, 25);
    list.erase(2);

    cout << "After insert/erase: ";
    for (Node<int>* node = list.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Front: " << list.front() << "\n";
    cout << "Back: " << list.back() << "\n";
    cout << "Size: " << list.get_size() << "\n";
    cout << "Empty: " << (list.empty() ? "true" : "false") << "\n";

    list.clear();
    cout << "After clear, empty: " << (list.empty() ? "true" : "false") << "\n";

    return 0;
}
