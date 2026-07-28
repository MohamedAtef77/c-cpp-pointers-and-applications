/**
 * @file    main.cpp
 * @brief   Copy semantics for a class that owns a raw pointer.
 *
 * @details
 * Demonstrates an `Integer` class that owns a raw `int*` and defines its own
 * copy constructor and copy-assignment operator to perform a deep copy.
 * Each copy allocates its own storage, so `a` and `b` remain independent and
 * each destructor safely deletes only the memory it owns.
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
    
    // Deep copy: the user-defined copy constructor allocates separate
    // storage for 'b', so 'a' and 'b' own independent memory.
    Integer b = a;

    cout << "a: ";
    a.Print();

    cout << "b: ";
    b.Print();

    // When 'a' and 'b' go out of scope, each destructor deletes only the
    // memory it owns; no double-deletion occurs.

    return 0;
}
