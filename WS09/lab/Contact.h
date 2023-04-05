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
            operator bool() const override;
            std::istream& read(std::istream& istr) override;
            std::ostream& write(std::ostream& ostr)const override;
    };

}

#endif