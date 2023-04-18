/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include <iostream>
#include "Contact.h"
#include "Tools.h"

using namespace std;

namespace sdds {
    Contact::Contact():Person() {}

    Contact::~Contact() {
        ~*this;
    }

    Contact::Contact(const Contact& other):Person(other) {
        this != &other ? *this = other : *this;
    }

    void Contact::operator~() {
        Person::operator~();
        this->m_address ? delete[] this->m_address : (void)0;
        this->m_city    ? delete[] this->m_city    : (void)0;
        this->m_address = nullptr;
        this->m_city    = nullptr;
    }

    Contact& Contact::operator=(const Contact& other) {
        this->m_address ? delete[] this->m_address : (void)0;
        this->m_city    ? delete[] this->m_city    : (void)0;
        this->m_address = nullptr;
        this->m_city    = nullptr;
        if(other) {
            Person::operator=(other);
            this->m_address = new char[strLen(other.m_address) + 1];
            this->m_city    = new char[strLen(other.m_city)    + 1];
            strCpy(this->m_address, other.m_address);
            strCpy(this->m_city,    other.m_city);
        }
        strCpy(this->m_province, other.m_province);
        strCpy(this->m_postalCode, other.m_postalCode);
        return *this;
    }

    Contact::operator bool()const {
        return Person::operator bool()
               && this->m_address != nullptr && strLen(this->m_address) != 0
               && this->m_city != nullptr    && strLen(this->m_city)    != 0
               && strLen(this->m_province)                              == 2
               && strLen(this->m_postalCode)                            == 6;
    }

    istream& Contact::read(istream& istr) {
        *this ? *this = Contact() : *this;
        Person::read(istr);
        char provinceBuffer[3]    {};
        char postalCodeBuffer[7]  {};
        this->m_address = dynRead(istr   , ',');
        this->m_city    = dynRead(istr   , ',');
        istr.getline(provinceBuffer , 3  , ',');
        istr.getline(postalCodeBuffer, 7, '\n');


        if ( !istr.fail() ) {
            strCpy(this->m_province,     provinceBuffer);
            strCpy(this->m_postalCode,   postalCodeBuffer);
        }
        else    ~*this; 
        return istr;
    }

    ostream& Contact::write(ostream& ostr) const {
        if(*this) {
            Person::write(ostr) 
                 << endl << m_address 
                 << endl << m_city 
                 << " " <<  m_province
                 << endl;
            for(int i = 0; i < 3 && ostr << this->m_postalCode[i]; i++);
            ostr << " ";
            for(int i = 3; i < 6 && ostr << this->m_postalCode[i]; i++);
            ostr << endl;
        }
        return ostr;
    }
}