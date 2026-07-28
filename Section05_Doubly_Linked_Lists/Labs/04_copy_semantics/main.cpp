/**
 * @file    main.cpp
 * @brief   Copy and move semantics for a doubly linked list
 *
 * @details
 * Demonstrates how a `DoubleList` behaves when it is copied or moved, and
 * how each instance manages its own nodes independently.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include <utility>
#include "doubly_list.h"
using namespace std;

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

/**
 * @brief  Prints a `DoubleList` from head to tail.
 *
 * @param list The list to print.
 */
void printForward(const DoubleList<int>& list)
{
    for (Node<int>* node = list.get_head(); node != nullptr; node = node->m_pNext) {
        cout << node->m_data;
        if (node->m_pNext) {
            cout << " -> ";
        }
    }
    cout << "\n";
}

/**
 * @brief  Entry point for the copy semantics linked list lab.
 *
 * @return 0 on success.
 */
int main()
{
    DoubleList<int> countedList(3, 7);
    DoubleList<int> initList{1, 2, 3, 4};

    cout << "Counted list: ";
    printForward(countedList);

    cout << "Initializer list: ";
    printForward(initList);

    DoubleList<int> copiedList(initList);
    copiedList.push_back(99);

    cout << "Original after copy is modified: ";
    printForward(initList);

    cout << "Copy (with extra element): ";
    printForward(copiedList);

    DoubleList<int> movedList(std::move(countedList));

    cout << "Moved-to list: ";
    printForward(movedList);
    cout << "Moved-from list is empty: " << (countedList.empty() ? "true" : "false") << "\n";

    return 0;
}
