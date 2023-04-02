#include <iostream>
#include <cstring>
#include "VRVideo.h"

using namespace std;

namespace sdds {

    VRVideo::VRVideo() : Video() { }

    VRVideo::VRVideo (int length, char* equipment) : Video(length) {
        if(!this->get()) {
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

    ostream& VRVideo::play(ostream& ostr) {
        if(*this) {
            ostr << "VRVideo requires" << this->m_equipment << endl
                 << "Video Length = " << Video::get(); 
        }
        return ostr; 
    }


}