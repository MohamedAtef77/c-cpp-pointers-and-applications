/**
 * @file    main.cpp
 * @brief   Introduction to function pointers.
 *
 * @details
 * Demonstrates declaring a function pointer, assigning it the address of a
 * free function, and invoking the pointed-to function both explicitly
 * (via the dereference operator) and implicitly (calling through the
 * pointer directly). Also demonstrates overloading a function on how the
 * arithmetic operation is selected: once via a switch on an operator
 * character, and once by taking the operation directly as a function
 * pointer argument.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include <stdexcept>
using namespace std;

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

/**
 * @brief  Adds two operands.
 *
 * @param  x  First operand.
 * @param  y  Second operand.
 * @return x + y.
 */
float add(float x, float y)
{
    return x + y;
}

/**
 * @brief  Subtracts two operands.
 *
 * @param  x  First operand.
 * @param  y  Second operand.
 * @return x - y.
 */
float subtract(float x, float y)
{
    return x - y ;
}

/**
 * @brief  Multiplies two operands.
 *
 * @param  x  First operand.
 * @param  y  Second operand.
 * @return x * y.
 */
float multiply(float x, float y)
{
    return x*y;
}

/**
 * @brief  Divides two operands, guarding against division by zero.
 *
 * @param  x  First operand (dividend).
 * @param  y  Second operand (divisor).
 * @return x / y, or 0 if \p y is zero (an error message is printed and
 *         the division-by-zero exception is caught internally).
 */
float divide(float x, float y)
{
    try
    {
        if (y == 0)
        {
            throw runtime_error("Division by zero!");
        }
        return x / y;
    }
    catch (const exception& e)
    {
        cout << "Error: " << e.what() << endl;
        return 0;
    }
}

/**
 * @brief  Selects the arithmetic operation matching \p op and applies it
 *         to \p x and \p y.
 *
 * @param  x   First operand.
 * @param  y   Second operand.
 * @param  op  Operator character ('+', '-', '*', '/').
 * @return Result of the selected operation, or 0 if \p op is unknown.
 */
float _operator(float x, float y, char op)
{
    switch (op)
    {
    case '+':
        return add(x, y);

    case '-':
        return subtract(x, y);

    case '*':
        return multiply(x, y);

    case '/':
        return divide(x, y);

    default:
        cout << "Invalid operator!" << endl;
        return 0;
    }
}

/**
 * @brief  Invokes the function pointed to by \p FnPtr on \p x and \p y.
 *
 * @param  x      First operand.
 * @param  y      Second operand.
 * @param  FnPtr  Pointer to the arithmetic function to execute.
 * @return Result of FnPtr(x, y).
 */
float _operator(float x, float y, float (*FnPtr)(float, float))
{
    return FnPtr(x, y);
}

/**
 * @brief  Entry point demonstrating both _operator() overloads.
 *
 * @return 0 on success.
 */
int main()
{
    /* char-operator overload */
    cout << _operator(4, 5, '+') << endl;
    cout << _operator(4, 5, '-') << endl;
    cout << _operator(4, 5, '*') << endl;
    cout << _operator(4, 5, '/') << endl;
    cout << _operator(4, 0, '/') << endl;

     /* function-pointer overload */
    cout << _operator(4, 5, &add) << endl;
    cout << _operator(4, 5, &subtract) << endl;
    cout << _operator(4, 5, &multiply) << endl;
    cout << _operator(4, 5, &divide) << endl;
}
