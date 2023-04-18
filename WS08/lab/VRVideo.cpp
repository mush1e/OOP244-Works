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
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds {

    VRVideo::VRVideo() : Video() { }

    VRVideo::VRVideo (int length, const char* equipment) : Video(length) {
        if(equipment != nullptr) {
            this->m_equipment = new char [strlen(equipment) + 1];
            strcpy(this->m_equipment, equipment);
        }
    }

    VRVideo::~VRVideo() {
        delete[] this->m_equipment;
        this->m_equipment = nullptr;
    }

    void VRVideo::load(istream& istr) {
        char buffer[255] {};
        Video::load(istr);
        istr.getline(buffer, 255);
        if(this->m_equipment != nullptr)     delete[] this->m_equipment;
        this->m_equipment = new char[strlen(buffer) + 1];
        strcpy(this->m_equipment, buffer);
    }

    VRVideo::operator bool() const{
        return  this->m_equipment != nullptr && this->get() != 0;
    }

    ostream& VRVideo::play(ostream& ostr) {
        if(*this) {
            ostr << "VRVideo requires " << this->m_equipment << endl
                 << "Video Length = " << Video::get(); 
        }
        return ostr; 
    }


}