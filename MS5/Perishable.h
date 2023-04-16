/*
Final Project Milestone 5
Module: POS
Filename: Perishable.h
Version 1.0
Author	Mustafa Siddiqui
Student ID: 117434225
Email: msiddiqui48@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/09  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#include <iostream>

#ifndef SDDS_PERISHABLE_H
#define SDDS_PERISHABLE_H

#include "Item.h" 
#include "Date.h"


namespace sdds {

    class Perishable : public Item {
        Date m_expiry {};
        public:
            char itemType() const override;
            Item& operator=(const Perishable& other);
            std::ostream&  write(std::ostream& ostr)  const override;
            std::istream&  read(std::istream& istr)         override;
            std::ofstream& save(std::ofstream& ostr)  const override;
            std::ifstream& load(std::ifstream& istr)        override; 
    };

}

#endif