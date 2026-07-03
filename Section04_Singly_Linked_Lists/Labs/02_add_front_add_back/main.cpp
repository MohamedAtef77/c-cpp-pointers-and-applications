/**
 * @file    main.cpp
 * @brief   Add elements to the front and back of a singly linked list
 *
 * @details
 * Demonstrates basic insertion into a singly linked list by adding values to
 * the front of the list and printing the resulting traversal order.
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
 * @brief  Entry point for the add-front/add-back linked list lab.
 *
 * @return 0 on success.
 */
int main()
{
    SingleList<int> list;

    list.Add(10);
    list.Add(20);
    list.Add(30);

    cout << "List contents: ";
    for (Node<int>* node = list.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << '\n';

    if (list.get_head()) {
        cout << "Head value: " << list.get_head()->m_data << '\n';
    } else {
        cout << "The list is empty." << '\n';
    }

    return 0;
}
