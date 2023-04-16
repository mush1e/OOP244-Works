/*
Final Project Milestone 5
Module: POS
Filename: Perishable.cpp
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
#include "Perishable.h"
#include "Date.h"
using namespace std;

namespace sdds {

    char Perishable::itemType() const {
        return 'P';
    }

    istream& Perishable::read(istream& istr)  {
        Item::read(istr);
        if(*this && !istr.fail()) {
            Date expDate {};
            expDate.dateOnly(true);
            cout << "Expiry date (YYYY/MM/DD)" << endl << "> ";
            istr >> expDate;
            expDate
                ? this->m_expiry = expDate
                : this->m_expiry, 
                  this->err = expDate.error();
        }
        return istr;
    }

    ostream& Perishable::write(ostream& ostr) const {
        Item::write(ostr);
        if (*this) {
            ((this->m_displayType == POS_LIST) 
                ? ostr <<  "  " << this->m_expiry << " |" 
                : ostr << "Expiry date: " << this->m_expiry
                       << endl << "=============^" << endl);
        }
        return ostr;
    }

    Item& Perishable::operator=(const Perishable& other) {
        Item::operator=(other);
        this->m_expiry = other.m_expiry;
        return *this;
    }


    ifstream& Perishable::load(ifstream& istr) {
        Item::load(istr);
        char ch;
        if(*this && !istr.fail()) {
            Date expDate {};
            expDate.dateOnly(true);
            istr >> ch >> expDate;
            expDate 
                ? this->m_expiry = expDate 
                : this->m_expiry, 
                  this->err = expDate.error();
        }
        return istr;
    }

    ofstream& Perishable::save(ofstream& ostr) const {
        Item::save(ostr);
        *this && ostr << "," << this->m_expiry;
        return ostr;
    }

}
