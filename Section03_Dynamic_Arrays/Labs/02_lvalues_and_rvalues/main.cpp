/**
 * @file    main.cpp
 * @brief   L-value and R-value binding demonstration in C++.
 *
 * @details
 * Demonstrates:
 *  - passing lvalues and rvalues to functions
 *  - overload resolution between `int &` and `const int &`
 *  - returning references from functions safely
 *  - value semantics for copy-by-value parameters
 *
 * The program prints which overload is selected and exercises both
 * lvalue and rvalue argument binding.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>

#if defined(__GNUC__) || defined(__clang__)
    #define FUNCTION_SIGNATURE __PRETTY_FUNCTION__
#else
    #define FUNCTION_SIGNATURE __FUNCSIG__
#endif

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

int &Increment(int &x)
{
    ++x;
    return x;
}

int Square(int x)
{
    return x * x;
}


void Show(int &value)
{
    std::cout << "Show(int&) called: " << FUNCTION_SIGNATURE << std::endl;
}


// Uncommented const-reference overload:
void Show(const int &value)
{
    std::cout << "Show(const int&) called: " << FUNCTION_SIGNATURE << std::endl;
}

void Show(int &&value)
{
    std::cout << "Show(int&&) called: " << FUNCTION_SIGNATURE << std::endl;
}

int main()
{
    int x = 5;

    // Pre-increment returns an lvalue and selects the const int& overload.
    Show(++x);

    // Post-increment returns an rvalue and selects the int&& overload.
    Show(x++);


}
