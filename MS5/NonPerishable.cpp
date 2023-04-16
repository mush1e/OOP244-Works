/*
Final Project Milestone 5
Module: POS
Filename: NonPerishable.cpp
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
#include "NonPerishable.h"

using namespace std;

namespace sdds {

    char NonPerishable::itemType() const {
        return 'N';
    }

    ostream& NonPerishable::write(ostream& ostr) const {
        Item::write(ostr);
        if(*this) {
            ostr  << ((this->m_displayType == POS_FORM)

                    ? "=============^\n" 
                    : "     N / A   |");
        }
        ostr.unsetf(ios::right);
        return ostr;
    }


}