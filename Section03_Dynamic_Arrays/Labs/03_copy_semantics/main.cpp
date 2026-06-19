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

using namespace std;



/*===========================================================================*
 *                      G L O B A L  F U N C T I O N S                       *
 *===========================================================================*/

class Integer
{
private:
    /* data */
    int *ptrData = nullptr;
public:
    void Print(void) const
    {
        if(ptrData != nullptr)
        {
            cout << *ptrData  << endl;
        }
    }
    Integer() = default;
    Integer(int data)
    {
        ptrData = new int{data};
    }
    ~Integer()
    {
        delete ptrData;
    }


    /* Copy Semantics */
    Integer(const Integer &other)
    {
        if(other.ptrData != nullptr)
        {
            ptrData = new int{*other.ptrData};
        }
    }

    Integer& operator = (const Integer &other)
    {
        if(this != &other)
        {
            delete ptrData;
            if(other.ptrData != nullptr)
            {
                ptrData = new int{*other.ptrData};
            }
            else
            {
                ptrData = nullptr;
            }
        }
        return *this;
    }
};


int main()
{
    // Create an Integer object
    Integer a(42);
    
    // Shallow copy: both 'a' and 'b' point to the same memory
    // Default copy constructor is used (memberwise copy)
    Integer b = a;
    
    cout << "a: ";
    a.Print();
    
    cout << "b: ";
    b.Print();
    
    // When 'a' goes out of scope, its destructor deletes the memory
    // When 'b' goes out of scope, its destructor tries to delete the same memory again
    // This causes a double-deletion error (crash or undefined behavior)
    
    return 0;
}
