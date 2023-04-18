/*
*****************************************************************************
Full Name  : Mustafa Siddiqui
Student ID#: 117434225
Email      : msiddiqui48@myseneca.ca
Date of completion    : 18 Apr 2023
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*****************************************************************************
*/
#include "Media.h"

using namespace std;

namespace sdds {

    ostream& operator << (ostream& ostr, Media& other) {
        return other.play(ostr);
    }

    istream& operator >> (istream& istr, Media& other) {
        other.load(istr);
        return istr;
    }
}