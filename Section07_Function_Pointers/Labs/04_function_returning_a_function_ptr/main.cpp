/**
 * @file    main.cpp
 * @brief   Function returning a function pointer - simple calculator.
 *
 * @details
 * Demonstrates a function whose return type is itself a function pointer.
 * GetOperationFn() takes an operator character read via cin and returns a
 * pointer to the matching free function (add, subtract, multiply, divide).
 * main() then invokes the returned pointer directly to produce the result.
 * The function pointer type is introduced via a typedef for readability.
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
 * @brief  Returns a pointer to the arithmetic function matching \p ch.
 *
 * @param  ch  Operator character ('+', '-', '*', '/').
 * @return Pointer to the matching function, or nullptr if \p ch is unknown.
 */
OperationFn GetOperationFn(char ch) // + - * /
{
    switch (ch)
    {
    case '+':
        return &add;

    case '-':
        return &subtract;

    case '*':
        return &multiply;

    case '/':
        return &divide;

    default:
        cout << "Invalid operator!" << endl;
        return nullptr;
    }
}

/**
 * @brief  Entry point for the function returning a function pointer lab.
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

    OperationFn FnPtr = GetOperationFn(op);

    if (FnPtr != nullptr)
    {
        cout << "Result: " << FnPtr(x, y) << endl;
    }

    return 0;
}
