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

#ifndef SDDS_CONTACT_H
#define SDDS_CONTACT_H

#include "Person.h"

namespace sdds {

    class Contact : public Person{
        char* m_address         {};
        char* m_city            {};
        char m_province[3]      {};
        char m_postalCode[7]    {};

        public:
            Contact();
            ~Contact();
            Contact(const Contact& other);
            Contact& operator=(const Contact& other);
            void operator~() override;
            operator bool() const override;
            std::istream& read(std::istream& istr) override;
            std::ostream& write(std::ostream& ostr)const override;
    };

}

#endif