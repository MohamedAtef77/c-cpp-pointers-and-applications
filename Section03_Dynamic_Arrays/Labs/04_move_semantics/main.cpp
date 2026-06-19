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
#include <utility>

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
    Integer()
    {
        cout << "Integer(): default constructor" << endl;
        ptrData = nullptr;
    }
    Integer(int data)
    {
        cout << "Integer(int): value constructor with " << data << endl;
        ptrData = new int{data};
    }
    ~Integer()
    {
        if (ptrData)
        {
            cout << "~Integer(): destructor deleting value " << *ptrData << endl;
        }
        else
        {
            cout << "~Integer(): destructor (null)" << endl;
        }
        delete ptrData;
    }


    /* Copy Semantics */
    Integer(const Integer &other)
    {
        if(other.ptrData != nullptr)
        {
            cout << "Integer(const Integer&): copy constructor, copying value " << *other.ptrData << endl;
            ptrData = new int{*other.ptrData};
        }
        else
        {
            cout << "Integer(const Integer&): copy constructor (other null)" << endl;
            ptrData = nullptr;
        }
    }

    Integer& operator = (const Integer &other)
    {
        if(this != &other)
        {
            if (other.ptrData)
            {
                cout << "operator=(const Integer&): copy-assigning value " << *other.ptrData << endl;
            }
            else
            {
                cout << "operator=(const Integer&): copy-assigning from null" << endl;
            }
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
    Integer(Integer&& other) noexcept
    {
        if (&other != this)
        {
            int val = other.ptrData ? *other.ptrData : 0;
            cout << "Integer(Integer&&): move constructor, taking value " << val << endl;
            delete ptrData;
            ptrData = other.ptrData;
            other.ptrData = nullptr;
        }
    }

    Integer& operator=(Integer&& other) noexcept
    {
        if (this != &other)
        {
            int val = other.ptrData ? *other.ptrData : 0;
            cout << "operator=(Integer&&): move-assigning, taking value " << val << endl;
            delete ptrData;
            ptrData = other.ptrData;
            other.ptrData = nullptr;
        }
        return *this;
    }
};

Integer Create(int x)
{
    Integer val{x};
    return val;
}


int main()
{
    Integer x;
    cout << "-------------------------------" << endl;
    x =  Create(10);
    cout << "-------------------------------" << endl;
    Integer y = Create(2);
}
