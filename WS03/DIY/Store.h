#ifndef SDDS_STORE_H
#define SDDS_STORE_H

#define MAX_NUMTOYS 10
#define MAX_SNAME 31

#include "Toys.h"

namespace sdds {
    class Store {

        char m_sName[MAX_SNAME];  
        int m_noOfToys; 
        int m_addToys; 
        Toys m_toy[MAX_NUMTOYS];
        
        public:
            void setStore(const char* sName, int no);
            void setToys(const char* tname, int sku, double price,int age);
            void display()const;
            void find(int sku);
            void setEmpty();
            
    };
}

#endif