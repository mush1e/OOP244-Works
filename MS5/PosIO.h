/*
Final Project Milestone 5
Module: Error
Filename: PosIO.h
Version 1.0
Author    Mustafa Siddiqui
Student ID: 117434225
Email: msiddiqui48@myseneca.ca
Revision History
-----------------------------------------------------------
Date        Reason
2023/03/20  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my project milestones.
-----------------------------------------------------------
*/
#include <iostream>
#ifndef SDDS_POSIO_H
#define SDDS_POSIO_H

namespace sdds {
    class PosIO{
        public:
            virtual std::ostream& write(std::ostream& ostr)  const = 0;
            virtual std::istream&  read(std::istream& istr)        = 0;
            virtual std::ofstream& save(std::ofstream& ostr) const = 0;
            virtual std::ifstream& load(std::ifstream& istr)       = 0; 
    };

    std::ostream& operator<<(std::ostream& ostr, const PosIO& ROp);
    std::ofstream& operator<<(std::ofstream& ostr, const PosIO& ROp);

    std::istream& operator>>(std::istream& istr, PosIO& ROp);
    std::ifstream& operator>>(std::ifstream& ifstr, PosIO& ROp);
}

#endif