/**
 * @file    main.cpp
 * @brief   Construct a doubly linked list with different constructors
 *
 * @details
 * Demonstrates how a `DoubleList` can be constructed using the default
 * constructor, a count-and-value constructor, and an initializer-list
 * constructor.
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
 * @brief  Entry point for the constructor-based linked list lab.
 *
 * @return 0 on success.
 */
int main()
{
    DoubleList<int> defaultList;
    DoubleList<int> countedList(3, 7);
    DoubleList<int> initList{1, 2, 3, 4};

    cout << "Default list (forward): ";
    for (Node<int>* node = defaultList.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Counted list (forward): ";
    for (Node<int>* node = countedList.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Initializer list (backward): ";
    for (Node<int>* node = initList.get_tail(); node != nullptr; node = node->m_pPrev) {
        cout << node->m_data;
        if (node->m_pPrev) {
            cout << " <- ";
        }
    }
    cout << "\n";

    return 0;
}
