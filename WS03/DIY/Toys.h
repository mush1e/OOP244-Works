/***********************************************************************
                 Toys.h
 Name: Mustafa Siddiqui
 Email: msiddiqui48@myseneca.ca
 Student Id: 117424225
 Date: 02/8/23
Authenticity Declaration:
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
***************************************************************************/
#ifndef SDDS_TOYS_H
#define SDDS_TOYS_H

#define MAX_TNAME 31

namespace sdds {

    class Toys {
        char m_tname[MAX_TNAME];
        int m_sku; 
        double m_price;
        int m_age;
        bool m_onSale;

        public:
            int getSKU() const;
            void addToys(const char* tname, int sku, double price,int age);
            void isSale(bool sale);
            void calSale();
            void display()const;
    };

}

#endif