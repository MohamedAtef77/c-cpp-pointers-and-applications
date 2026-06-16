/**
 * @file    main.cpp
 * @brief   Demonstrates passing static arrays to functions in C++.
 *
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
void Print(array<int,5> &pArr)
{
    sort(pArr.begin(),pArr.end());
    for(auto x: pArr)
    {
        cout << x << "\t";
    }

    cout << endl;
}
int main(void)
{
    array<int,5> arr{1,2,3,4,5};


    // for(auto it: arr)
    // {
    //     cout << it << endl;
    // }

    cout << arr.at(0) << endl; /* Outisde boundaries access will throw an exception */
    Print(arr);
}