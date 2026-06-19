/**
 * @file    main.cpp
 * @brief   Demonstrates dynamic memory allocation in C++ using new[].
 *
 * @details
 * Allocates integer arrays on the heap with `new[]`, copies array data,
 * prints heap-stored values, and correctly frees allocated memory with
 * `delete[]`.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <algorithm>
#include <iostream>
#include <array>

using namespace std;
/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

void Print(int *p, int size)
{
    for(int i = 0; i != size; ++i)
    {
        cout << p[i] << "\t";
    }

    cout << endl;
}
int main(void)
{
    int *p = new int[5]{1,2,3,4,5};
    int *p2 = new int [10];

    Print(p,5);

    copy(p,p+5,p2);


    delete []p;

    p2[5] = 12;
    Print(p2,6);

}