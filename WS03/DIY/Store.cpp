#include <iostream>
#include <cstring>
#include "Store.h"

namespace sdds {

    void Store::setStore(const char* sName, int no) {

        if(sName || no + m_noOfToys > MAX_NUMTOYS) {
            memset(m_sName, 0, MAX_SNAME);
            memset(m_toy,   0, MAX_NUMTOYS * sizeof(Toys));
            m_noOfToys, m_addToys = 0, 0;
        }

        else {
            strcpy(m_sName, sName);
            m_addToys = no;
        }

    }

    void Store::setToys(const char* tname, int sku, double price,int age) {
        if (m_addToys < m_noOfToys)
            m_toy[m_addToys].addToys(tname, sku, price, age);
    }

}