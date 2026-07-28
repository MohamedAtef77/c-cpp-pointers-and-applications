/**
 * @file    main.cpp
 * @brief   Copy and move semantics for `Integer` and `GArray`.
 *
 * @details
 * Revisits the `Integer` copy/move demonstration and extends it to
 * `Basic::GArray`, exercising its copy constructor, move constructor,
 * copy-assignment, and move-assignment to show that a dynamically-allocated
 * array container can be copied and moved just as safely as a single
 * pointer-owning object.
 *
 * @author  Mohamed Atef
 * @date    2026-06-16
 */

/*===========================================================================*
 *                          F I L E  I N C L U S I O N S                     *
 *===========================================================================*/
#include <iostream>
#include <utility>
#include "GArray.h"

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

    cout << "\n=== GArray copy/move demo ===" << endl;
    using Basic::GArray;

    GArray<int> ga1(3, 7);
    cout << "ga1 (created with 3 copies of 7): ";
    for (size_t i = 0; i < ga1.GetSize(); ++i) cout << ga1[i] << " ";
    cout << endl;

    cout << "Copy-construct ga2 from ga1" << endl;
    GArray<int> ga2 = ga1;
    cout << "ga2: "; for (size_t i = 0; i < ga2.GetSize(); ++i) cout << ga2[i] << " "; cout << endl;

    cout << "Move-construct ga3 from std::move(ga1)" << endl;
    GArray<int> ga3 = std::move(ga1);
    cout << "ga1 size after move: " << ga1.GetSize() << ", ga3 size: " << ga3.GetSize() << endl;

    cout << "Copy-assign ga4 = ga2" << endl;
    GArray<int> ga4;
    ga4 = ga2;
    cout << "ga4: "; for (size_t i = 0; i < ga4.GetSize(); ++i) cout << ga4[i] << " "; cout << endl;

    cout << "Move-assign ga4 = GArray<int>(2, 9)" << endl;
    ga4 = GArray<int>(2, 9);
    cout << "ga4 after move-assign: "; for (size_t i = 0; i < ga4.GetSize(); ++i) cout << ga4[i] << " "; cout << endl;
}
