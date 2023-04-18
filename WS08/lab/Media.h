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

#ifndef SDDS_MEDIA_H
#define SDDS_MEDIA_H
namespace sdds {

    class Media {
        public:
            virtual std::ostream& play(std::ostream& ostr) = 0;
            virtual void load(std::istream& istr)          = 0;
            virtual ~Media() {};
    };
    std::ostream& operator << (std::ostream& ostr, Media& other);
    std::istream& operator >> (std::istream& istr, Media& other);
}

#endif