/**
 * @file    main.cpp
 * @brief   Member access on a doubly linked list
 *
 * @details
 * Demonstrates indexed element access (`at`) and stream printing (`print`)
 * on a `DoubleList`, alongside the previously implemented insert, erase,
 * front/back, size, and clear operations.
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
 * @brief  Entry point for the member accessing linked list lab.
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
    list.print(cout);
    cout << "\n";

    list.insert(1, 25);
    list.erase(2);

    cout << "After insert/erase: ";
    list.print(cout);
    cout << "\n";

    cout << "Front: " << list.front() << "\n";
    cout << "Back: " << list.back() << "\n";
    cout << "Element at index 1: " << list.at(1) << "\n";
    cout << "Size: " << list.get_size() << "\n";
    cout << "Empty: " << (list.empty() ? "true" : "false") << "\n";

    list.clear();
    cout << "After clear, empty: " << (list.empty() ? "true" : "false") << "\n";

    return 0;
}
