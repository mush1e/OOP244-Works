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
        return this->m_address != nullptr;
    }

    istream& Contact::read(istream& istr) {
        *this ? *this = Contact() : *this;
        Person::read(istr);
        bool fail                   {};
        char addressBuffer[255]     {};
        char cityBuffer[255]        {};
        char provinceBuffer[255]    {};
        char postalCodeBuffer[255]  {};
        istr.getline(addressBuffer  , 255, ',');
        istr.getline(cityBuffer     , 255, ',');
        istr.getline(provinceBuffer , 255, ',');
        istr >> postalCodeBuffer;
        strLen(addressBuffer) == 0
        ||  strLen(cityBuffer) == 0
        ||  strLen(provinceBuffer) != 2
        ||  strLen(provinceBuffer) != 6
            ?   fail = true   
            :   bool   {};
        if ( !fail && !istr.fail() ) {
            this->m_address ? delete[] this->m_address : (void)0;
            this->m_city    ? delete[] this->m_city    : (void)0;
            this->m_address = new char[strLen(addressBuffer) + 1];
            this->m_city    = new char[strLen(cityBuffer)    + 1];
            strCpy(this->m_address, addressBuffer);
            strCpy(this->m_city,    cityBuffer);
            strCpy(this->m_province, provinceBuffer);
            strCpy(this->m_postalCode, postalCodeBuffer);
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