/**
 * @file    main.cpp
 * @brief   Add elements to the front and back of a doubly linked list
 *
 * @details
 * Demonstrates basic insertion into a doubly linked list by adding values to
 * both the front and back of the list, then traversing it forward from the
 * head and backward from the tail.
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
 * @brief  Entry point for the add-front/add-back linked list lab.
 *
 * @return 0 on success.
 */
int main()
{
    DoubleList<int> list;

    list.push_back(20);
    list.push_back(30);
    list.push_front(10);

    cout << "List contents (forward): ";
    for (Node<int>* node = list.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << '\n';

    cout << "List contents (backward): ";
    for (Node<int>* node = list.get_tail(); node != nullptr; node = node->m_pPrev) {
        cout << node->m_data;
        if (node->m_pPrev) {
            cout << " <- ";
        }
    }
    cout << '\n';

    if (list.get_head()) {
        cout << "Head value: " << list.get_head()->m_data << '\n';
        cout << "Tail value: " << list.get_tail()->m_data << '\n';
    } else {
        cout << "The list is empty." << '\n';
    }

    return 0;
}
