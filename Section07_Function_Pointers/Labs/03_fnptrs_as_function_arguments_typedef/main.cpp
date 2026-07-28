/**
 * @file    main.cpp
 * @brief   Function pointers as function arguments - simple calculator.
 *
 * @details
 * Demonstrates selecting one of several free functions (add, subtract,
 * multiply, divide) at runtime based on an operator character read via
 * cin. The Operation() function switches on that character, assigns the
 * matching free function's address to a function pointer, then invokes
 * the pointer to produce the result. The function pointer type is
 * introduced via a typedef for readability.
 *
 * @author  Mohamed Atef
 * @date    2026-07-29
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
using namespace std;

/*===========================================================================*
 *                      T Y P E  D E F I N I T I O N S                       *
 *===========================================================================*/

/**
 * @brief  Pointer to a function taking two floats and returning a float.
 */
typedef float (*OperationFn)(float, float);

/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

float add(float x, float y)
{
    return x + y;
}

float subtract(float x, float y)
{
    return x - y;
}

float multiply(float x, float y)
{
    return x * y;
}

float divide(float x, float y)
{
    return x / y;
}

/**
 * @brief  Selects the arithmetic function matching \p ch, invokes it on
 *         \p x and \p y, prints the result, and returns it.
 *
 * @param  x   First operand.
 * @param  y   Second operand.
 * @param  ch  Operator character ('+', '-', '*', '/').
 * @return Result of the selected operation, or 0 if \p ch is unknown.
 */
float Operation(float x, float y, char ch) // + - * /
{
    float result{};
    OperationFn FnPtr = nullptr;

    switch (ch)
    {
    case '+':
        FnPtr = &add;
        break;

    case '-':
        FnPtr = &subtract;
        break;

    case '*':
        FnPtr = &multiply;
        break;

    case '/':
        FnPtr = &divide;
        break;

    default:
        cout << "Invalid operator!" << endl;
        return result;
    }

    result = FnPtr(x, y);
    cout << "Result: " << result << endl;
    return result;
}

/**
 * @brief  Entry point for the function pointers as arguments lab.
 *
 * @return 0 on success.
 */
int main()
{
    float x, y;
    char op;

    cout << "Enter first operand: ";
    cin >> x;

    cout << "Enter operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter second operand: ";
    cin >> y;

    Operation(x, y, op);

    return 0;
}
