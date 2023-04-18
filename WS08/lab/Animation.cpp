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
#include "Animation.h"

using namespace std;

namespace sdds {

    Animation::Animation() : Video() {}

    Animation::Animation(int length, int dimension) : Video (length) {
        dimension == 2 || dimension == 3 
            ? this->m_dimension = dimension 
            : this->m_dimension = 0;
    }

    void Animation::load(istream& istr) {
        int dimension;  
        Video::load(istr);
        istr >> dimension;
        istr.ignore(1000, '\n');
        dimension == 2 || dimension == 3 
            ? this->m_dimension = dimension 
            : this->m_dimension = 0;       
    }

    Animation::operator bool() const {
        return (this->m_dimension == 2 || this->m_dimension == 3) && this->get() != 0;
    }

    ostream& Animation::play(ostream& ostr) {
        if(*this) {
            ostr << "Animation is in " << this->m_dimension << "-D" << endl
                 << "Video Length = " << this->get();
        }
        return ostr;
    }
}
