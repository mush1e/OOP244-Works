#include <iostream>
#include <cstring>
#include <iomanip>

#include "Store.h"

using namespace std;

namespace sdds {

    void Store::setStore(const char* sName, int no) {
        if(sName == nullptr || no > MAX_NUMTOYS) {
            setEmpty();
        }
        else {
            strcpy(m_sName, sName);
            m_noOfToys = no;
            m_addToys = 0;
        }
    }

    void Store::setToys(const char* tname, int sku, double price,int age) {
        if (m_addToys < m_noOfToys)
            m_toy[m_addToys++].addToys(tname, sku, price, age);
    }

    void Store::display() const {
        cout << left << setfill('*') << setw(60) 
            << "" << endl
            << m_sName << endl
            << setfill('*') << setw(60) 
            << "" << endl << "list of the toys" << endl;

        cout << right
            << setfill(' ') 
            << setw(30) << "SKU"
            << setw(10) << "Age"
            << setw(11) << "Price"
            << setw(10) << "Sale"
            << endl;
        
        for(int i = 0; i < m_addToys; i++) {
            cout << "Toy[" << i + 1 << "] :";
            m_toy[i].display();
            cout << endl;
        }
    }

    void Store::find(int sku) {
        for(int i = 0; i < m_addToys; i++)
            if(m_toy[i].getSKU() == sku) {
                m_toy[i].isSale(true);
                m_toy[i].calSale();
            }
    }

    void Store::setEmpty() {
            memset(m_sName, 0, MAX_SNAME);
            memset(m_toy,   0, MAX_NUMTOYS * sizeof(Toys));
            m_noOfToys = 0;
            m_addToys  = 0;
    }
}