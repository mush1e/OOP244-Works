/*
Final Project Milestone 3
Module: Error
Filename: PosIO.cpp
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
#include "PosIO.h"

using namespace std;

namespace sdds {
    ostream& operator<<(ostream& ostr, const PosIO& ROp) {
        return ROp.write(ostr);
    }

    ofstream& operator<<(ofstream& ofstr, const PosIO& ROp) {
        return ROp.save(ofstr);
    }

    istream& operator>>(istream& istr, PosIO& ROp) {
        return ROp.read(istr);
    }

    ifstream& operator>>(ifstream& ifstr, PosIO& ROp) {
        return ROp.load(ifstr);
    }
}