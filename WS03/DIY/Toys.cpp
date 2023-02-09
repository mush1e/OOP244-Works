/***********************************************************************
                 Toys.cpp
 Name: Mustafa Siddiqui
 Email: msiddiqui48@myseneca.ca
 Student Id: 117424225
 Date: 02/8/23
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***************************************************************************/
#include <iostream>
#include <cstring>
#include <iomanip>

#include "Toys.h"

using namespace std;

namespace sdds {
    bool m_Validity = false;
     
    int Toys::getSKU() const {
        return m_sku;
    }

    void Toys::addToys(const char* tname, int sku, double price,int age) {
        if (tname == nullptr || sku < 10000000 || price < 0 || age < 0) {
            memset(m_tname, 0 , MAX_TNAME);
            sku = 0;
            price = 0;
            age = 0;
            m_Validity = false;
        }
        else {
            strcpy(m_tname, tname);
            m_sku = sku;
            m_price = price;
            m_age = age;
            m_Validity = true;
        }
    }

    void Toys::isSale(bool sale) {
        m_onSale = sale;
    }

    void Toys::calSale() {
        m_price *= 0.8;
    }

    void Toys::display() const {
        if (m_Validity) {
            cout << left << setw(15) 
                << m_tname 
                << right << setw(10) 
                << m_sku << setw(6) 
                << m_age << setw(12)
                << fixed << setprecision(2) << m_price;
                if (m_onSale)
                {
                    cout << right << setw(11) << "On Sale ";
                }
                else if (!m_onSale)
                {
                    cout << setw(8) << " ";
                }
        }
        else
            cout << "Invalid Toy";
    }
}