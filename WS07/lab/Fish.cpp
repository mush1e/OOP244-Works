/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Fish.h"

using namespace std;

namespace sdds {
    Fish::Fish(const char* name, int age) : Pet(name, age, m_create) {}

    Fish& Fish::feed() {
        Pet::feed();
        this->isAlive() ? this->addCharge(m_feed) : this->addCharge(0);
        return *this;
    }

    Fish& Fish::reSpawn() {
        Pet::reSpawn();
        this->addCharge(m_respawn);
        return *this;
    }

    Fish& Fish::operator++(int) {
        if(isAlive())   applyHealthDelta(0.20 * (getFeeds() - 1));
        Pet::operator++(0);
        return *this;
    }

    Fish& Fish::operator=(const Fish& other) {
        if(this != &other) {
            Pet::operator=(other);
            this->addCharge((m_create + m_base) * 2);
        }
        return *this;
    }

    ostream &operator<<(ostream &ostr, Fish &ROp) {
        ostr << "** Generic Fish **" << endl; 
        return ROp.outputData(ostr);
    }

}