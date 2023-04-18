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
#include "Video.h"

using namespace std;

namespace sdds {

    Video::Video()  {}    // Values already initialised to default

    Video::Video (const int value) {
        this->m_length = value > 0 ? value : 0;
    }

    int Video::get() const {
        return this->m_length;
    }

    void Video::load(std::istream& istr) {
        char delim;
        istr >> this->m_length >> delim;
    }

}