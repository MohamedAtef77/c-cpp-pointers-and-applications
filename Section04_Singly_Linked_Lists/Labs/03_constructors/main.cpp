/**
 * @file    main.cpp
 * @brief   Construct a singly linked list with different constructors
 *
 * @details
 * Demonstrates how a `SingleList` can be constructed using the default
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
#include "single_list.h"
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
    SingleList<int> defaultList;
    SingleList<int> countedList(3, 7);
    SingleList<int> initList{1, 2, 3, 4};

    cout << "Default list: ";
    for (Node<int>* node = defaultList.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Counted list: ";
    for (Node<int>* node = countedList.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    cout << "Initializer list: ";
    for (Node<int>* node = initList.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";

    return 0;
}
