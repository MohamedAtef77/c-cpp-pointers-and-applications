/**
 * @file    main.cpp
 * @brief   Demonstrates dynamic 2D array allocation and cleanup.
 *
 * @details
 * Builds a 2x3 matrix using `new` for rows and row pointers, modifies
 * its contents, prints the matrix, and then properly deallocates the
 * dynamic memory to avoid leaks.
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

void Print2D(int **pMatrix, int rows, int cols)
{
    for(int i = 0; i != rows; ++i)
    {
        for(int j = 0; j != cols; ++j)
        {
            cout << pMatrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
}

int main(void)
{
    // Create a 2x3 matrix dynamically
    int **pMatrix = new int *[2]{nullptr, nullptr};

    pMatrix[0] = new int[3]{1,2,3};
    pMatrix[1] = new int[3]{4,5,6};
    
    cout << "Original Matrix:" << endl;
    Print2D(pMatrix, 2, 3);
    
    // Modify elements
    pMatrix[0][1] = 20;
    pMatrix[1][0] = 40;
    
    cout << "Modified Matrix:" << endl;
    Print2D(pMatrix, 2, 3);
    
    // Clean up - delete rows first, then the array of pointers
    delete[] pMatrix[0];
    delete[] pMatrix[1];
    delete[] pMatrix;

}