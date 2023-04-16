/*
Final Project Milestone 5
Module: Error
Filename: Item.h
Version 1.0
Author    Mustafa Siddiqui
Student ID: 117434225
Email: msiddiqui48@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/20  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#include <fstream>

#ifndef SDDS_ITEM_H
#define SDDS_ITEM_H

#include "PosIO.h"
#include "POS.h"
#include "Error.h"

namespace sdds {
    class Item : public PosIO {
        char m_SKU[MAX_SKU_LEN + 1] {};
        char* m_itemName        = nullptr;
        double m_price              {};
        bool m_isTaxed              {};
        int m_quantity              {};
    
        protected:
            int m_displayType       {};
            Error err               {};

        public:
            Item();
            virtual ~Item();
            Item(const Item& other);
            virtual Item& operator=(const Item& other);
            bool operator==(const char* name)  const;
            bool operator>(const Item& other)  const;
            int operator+=(const int value);
            int operator-=(const int value);
            operator bool() const;
            
            char* getName() const;

            virtual char itemType() const = 0;
            double cost()  const;
            int quantity() const;

            Item& clear();
            Item& displayType(int posValue);
            std::ostream&  bprint(std::ostream &ostr) const;
            std::ostream&  write(std::ostream& ostr)  const override;
            std::istream&  read(std::istream& istr)         override;
            std::ofstream& save(std::ofstream& ostr)  const override;
            std::ifstream& load(std::ifstream& istr)        override; 

    };

    double operator+=(double& value, const Item& ROp);

}

#endif